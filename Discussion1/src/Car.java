public class Car{
    public String make;
    public String model;

    public Car(String make, String model){
        this.make = make;
        this.model = model;
    }

    public static void main(String[] args){
        Car car = new Car("Honda", "Civic");
        System.out.println(car.make + " " + car.model);
        car.model = "Accord";
        System.out.println(car.make + " " + car.model);
    }
}
