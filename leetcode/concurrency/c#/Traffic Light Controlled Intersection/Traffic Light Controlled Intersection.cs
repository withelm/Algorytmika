public class TrafficLight
{
    private int _direct { get; set; }

    public TrafficLight()
    {
        _direct = 1;
    }

    public void CarArrived(
        int carId, // ID of the car
        int roadId, // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction, // Direction of the car
        Action turnGreen, // Use turnGreen() to turn light to green on current road
        Action crossCar
    ) // Use crossCar() to make car cross the intersection
    {
        if (roadId != _direct)
        {
            turnGreen.Invoke();
            _direct = roadId;
        }
        crossCar.Invoke();
    }
}
