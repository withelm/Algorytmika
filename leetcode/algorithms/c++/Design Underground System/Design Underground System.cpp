class Pkt
{
public:
    string stationName;
    int t;
};
class UndergroundSystem
{
private:
    map<int, Pkt> in;
    map<vector<string>, vector<int>> base2;

public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        Pkt tmp;
        tmp.stationName = stationName;
        tmp.t = t;
        in[id] = tmp;
    }

    void checkOut(int id, string stationName, int t)
    {
        auto curr = in[id];
        base2[{curr.stationName, stationName}].push_back(t - curr.t);
    }

    double getAverageTime(string startStation, string endStation)
    {
        double r = 0;
        vector<string> key = {startStation, endStation};
        for (auto &x : base2[key])
            r += x;

        return r / base2[key].size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */