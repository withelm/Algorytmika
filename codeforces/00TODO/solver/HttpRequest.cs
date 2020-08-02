using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Net.Security;
using System.Security.Cryptography.X509Certificates;
using System.Text;

namespace solver
{
    public class HttpRequest
    {
        private static bool ValidateRemoteCertificate(object sender, X509Certificate certificate, X509Chain chain, SslPolicyErrors policyErrors)
        {
            return true;
        }

        public static String SendHttpWebPost(string strUrl)
        {
            string result = string.Empty;
            ServicePointManager.ServerCertificateValidationCallback += new System.Net.Security.RemoteCertificateValidationCallback(ValidateRemoteCertificate);

            HttpWebRequest request = null;
            HttpWebResponse response = null;
            try
            {
                Uri url = new Uri(strUrl);
                request = (HttpWebRequest)WebRequest.Create(url);
                request.Method = WebRequestMethods.Http.Get;
                request.KeepAlive = true;
                request.Timeout = 5000;

                // get response
                response = (HttpWebResponse)request.GetResponse();
                Stream responseStream = response.GetResponseStream();
                string strStatus = ((HttpWebResponse)response).StatusDescription;
                StreamReader streamReader = new StreamReader(responseStream);
                result = streamReader.ReadToEnd();

                // close connection
                streamReader.Close();
                responseStream.Close();
                response.Close();
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
            return result;
        }
    }
}