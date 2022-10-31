import java.util.concurrent.*;   
//a shared resource or class.   
class Shared   
{   
static int count = 0;   
}   
class DemoThread extends Thread   
{   
//object of the Semaphore class  
Semaphore semaphore;   
//variable for storing the thread name  
String threadName;   
public DemoThread(Semaphore semaphore, String threadName)   
{   
super(threadName);   
this.semaphore = semaphore;   
this.threadName = threadName;   
}   
@Override  
public void run()   
{   
// run by thread A   
if(this.getName().equals("A"))   
{   
System.out.println("Starting thread " + threadName);   
try  
{   
// First, get a permit.   
System.out.println(threadName + " is waiting for a permit.");   
//acquiring the lock   
semaphore.acquire();   
System.out.println(threadName + " gets a permit.");  
//current thread A is accessing the resource and the   
//other threads are waiting for to get the resource   
//until the thread A release the lock   
for(int i=0; i < 5; i++)   
{   
//thread A has acquired the resource   
//hence the value of the count is incremented to 1    
Shared.count++;   
System.out.println(threadName + ": " + Shared.count);   
//now, allowing a context switch for thread B to execute   
//sleeps thread for 1 second  
Thread.sleep(1000);   
}   
}   
catch (InterruptedException e)   
{   
e.printStackTrace();   
}   
//release the permit  
System.out.println("Thread " +threadName + " releases the permit.");   
semaphore.release();   
}   
// run by thread B   
else  
{   
System.out.println("Starting thread " + threadName);   
try  
{   
//first, get a permit  
System.out.println("Thread " +threadName + " is waiting for a permit.");   
//acquiring the lock   
semaphore.acquire();   
System.out.println("Thread " +threadName + " gets a permit.");   
//Now, accessing the shared resource.   
//other waiting threads will wait, until this   
//thread release the lock   
for(int i=0; i < 5; i++)   
{   
//decrements the count value      
Shared.count--;   
System.out.println(threadName + ": " + Shared.count);   
//Now, allowing a context switch -- if possible.   
//for thread A to execute   
//sleeps thread for 1 second  
Thread.sleep(1000);   
}   
}   
catch (InterruptedException e)   
{   
e.printStackTrace();   
}   
//release the permit   
System.out.println("Thread " +threadName + " releases the permit.");   
//release the resource  
semaphore.release();   
}   
}   
}   
//creating driver class  
public class SemaphoreAsLock   
{   
public static void main(String args[]) throws InterruptedException   
{   
//creating the constructor of the Semaphore with initial permit 1   
Semaphore semaphore = new Semaphore(1);   
//creating two threads with the name A and B   
//thread A increments the count value   
//while the thread B decrements the count value  
DemoThread dt1 = new DemoThread(semaphore, "A");   
DemoThread dt2 = new DemoThread(semaphore, "B");   
//stating both threads A and B   
dt1.start();   
dt2.start();   
//waiting for thread A   
dt1.join();   
//waiting for thread B  
dt2.join();   
//after completing the execution of the threads, the count value will be 0 always  
System.out.println("count: " + Shared.count);   
}   
} 
