class Car{
	int price = 0;
	void gear(){
		System.out.println("Car gear");
	}
}
class BMW extends Car{
	int price = 100;
	void gear(){
		System.out.println("BMW gear");
	}
	void sound(){
		//super();  // call to super must be first statement in constructor
		System.out.println("BMW sound");
	}
	static void tool(){
		Test t = new Test();
		System.out.println(t.time);
		
		System.out.println(super.price);  // non-static variable super cannot be referenced from a static context
	}
}
public class Test{
	int time;
	public static void main(String args[]){
		Car c = new BMW();
		c.gear();
		BMW b = new BMW();
		b.tool();
		//c.sound();
	}
}