import java.util.Scanner;
public class p2_a{

public static void main(String args[]){
	
	int i,j,temp;
	int a[] = new int[5];
	
	Scanner sc = new Scanner(System.in);
	System.out.println("Enter total number of elements : ");
	int n=sc.nextInt();
	System.out.println("Enter Elements:");
	for(i=0;i<n;i++)
	a[i]=sc.nextInt();
	for(i=0;i<n;i++)
	{
	  for(j=0;j<n-1;j++)
	  {
	   if(a[j]>a[j+1])
	   {
	     temp=a[j];
	     a[j]=a[j+1];
	     a[j+1]=temp;
	   }
}
}

System.out.println("The sorted elements are: ");
for(i=0;i<n;i++)
System.out.print("\t"+a[i]);


System.out.println("");
}
}
