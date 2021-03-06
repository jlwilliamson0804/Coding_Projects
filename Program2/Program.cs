/* 
 Joseph Williamson
 Short Program2
 9/1/2020
 Purpose: To create a simple console app that
    takes in 3 int values from the user and
    fins sum,ave,smallest, and largest value
 */
using System;
using System.Collections.Generic;

class calculate
{
    static void Main()
    {
        string val1,val2,val3;
        bool flag = true;
        while (flag == true)
        {
            Console.WriteLine("Enter 3 Integers: "); //asks user for 3 values
            val1 = Console.ReadLine(); //takes first line
            val2 = Console.ReadLine(); //takes second line of input
            val3 = Console.ReadLine(); //takes third line of input
            int x = Convert.ToInt32(val1); //converts the input to integers
            int y = Convert.ToInt32(val2); //
            int z = Convert.ToInt32(val3); //
            Console.WriteLine("Your inputs: {0} {1} {2}", x, y, z); //display values to confirm
            
            //find sum
            int sum = x + y + z;
            Console.WriteLine("The sum = "+ sum);

            //find average
            double average = sum / 3;
            int ave = Convert.ToInt32(average);
            Console.WriteLine("The average = " + ave);

            //find smallest
            int small = x;
            if (y < small)
                small = y;
            if (z < small)
                small = z;
            Console.WriteLine("The smallest value = " + small);

            //find largest
            int large = x;
            if (y > large)
                large = y;
            if (z > large)
                large = z;
            Console.WriteLine("The largest value = " + large);

            //asks if user wants to keep going
            Console.WriteLine("Keep Trying? y or n");
            string ans = Console.ReadLine();
            if (ans == "y" || ans == "Y")
            {
                flag = true;
            }
            else if (ans == "n" || ans == "N")
            {
                flag = false;
            }
            else flag = false;
        }
    }
}
