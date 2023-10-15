// Java program to Illustrate isAlive() Method
// of Thread class

// Main class extending Thread class
public class oneThread extends Thread {

	// Method 1
	// run() method for thread
	public void run()
	{

		// Print statement
		System.out.println("geeks ");

		// Try block to check for exceptions
		try {
		
			// making thread to sleep for 300 nano-seconds
		// using sleep() method 
			Thread.sleep(300);
		}

		// Catch block to handle InterruptedException
		catch (InterruptedException ie) {
		}

		// Display message when exception occurred
		System.out.println("forgeeks ");
	}

	// Method 2
	// Main driver method
	public static void main(String[] args)
	{
		// Creating threads using above class as
		// it is extending Thread class
		oneThread c1 = new oneThread();
		oneThread c2 = new oneThread();

		// Starting threads
		c1.start();
		c2.start();

		// Checking whether thread is alive or not
		// Returning boolean true if alive else false
		System.out.println(c1.isAlive());
		System.out.println(c2.isAlive());
	}
}
