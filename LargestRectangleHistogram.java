import java.util.*;

public class LargestRectangleHistogram
{
    public static int largestRectangleArea(int[] heights)
    {
        int i,maxArea;
        Stack<Integer> stack=new Stack<>();
        stack.push(-1);
        maxArea=heights[0];
        int left_smaller[]=new int[heights.length];
        int right_smaller[]=new int[heights.length];
        for(i=0;i<=heights.length-1;i++)
        {
            left_smaller[i]=-1;
            right_smaller[i]=heights.length;
        }
        i=0;
        while(i<=heights.length-1)
        {
            while(!stack.empty() && stack.peek()!=-1 && heights[i]<heights[stack.peek()])
            {
                right_smaller[stack.peek()]=i;
                stack.pop();
            }
            if(i>0 && heights[i]==heights[i-1])
                left_smaller[i]=left_smaller[i-1];
            else
                left_smaller[i]=stack.peek();
            stack.push(i);
            i+=1;
        }
        for(i=0;i<=heights.length-1;i++)
            maxArea=Math.max(maxArea,heights[i]*(right_smaller[i]-left_smaller[i]-1));
            
        return maxArea;
    }
    
    public static void main(String[] args)
	{
	    int i,n,width;
	    Scanner sc=new Scanner(System.in);
        System.out.print("Enter the number of bars in the Histogram: ");
	    n=sc.nextInt();
	    int[] heights=new int[n];
        System.out.print("\nEnter heights of the bars in the Histogram: ");
	    for(i=0;i<=n-1;i++)
            heights[i]=sc.nextInt();
        System.out.print("Enter the width of bars in the Histogram: ");
	    width=sc.nextInt();
        sc.close();
	    System.out.println("\nArea of the largest rectangle in the Histogram: "+(largestRectangleArea(heights)*width));
	}
}
