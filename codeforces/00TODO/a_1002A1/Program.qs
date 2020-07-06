namespace _1002A1 {

    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic
  

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            for(i in 1 .. Length(qs)) {
                H(qs[i-1]);
            }
        }
    }
}

