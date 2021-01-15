using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void print(ref int x)
        {
            Console.WriteLine("프린트 함수 Call");
            Console.WriteLine("변경전 값 : {0}",x);
            x = 10;
            Console.WriteLine("변경후 값 : {0}", x);
        }
        
        static void UpDownCasting(int num)
        {
            Console.WriteLine(num);
        }

        static int Factorial(int n)
        {
            if(n==1 || n == 0)
            {
                return 1;
            }
            else
            {
                return n * Factorial(n - 1);
            }
        }

        static void one(int num)
        {
            for(int i = 0; i < num; i++)
            {
                for(int j = 0; j<num; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }

        }

        static void two(int num)
        {
            for (int i = 0; i < num; i++)
            {
                for (int j = 0; j < num; j++)
                {
                    if (i < j)
                    {
                        break;
                    }
                    else
                    {
                        Console.Write("*");
                    }
                }
                Console.WriteLine();
            }

        }

        static void three(int num)
        {
            for (int i = 0; i < num; i++)
            {
                for (int j = 0; j < num; j++)
                {
                    if (i+j>=4)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
                Console.WriteLine();
            }

        }

        static void four(int num)
        {
            for (int i = 0; i < num; i++)
            {
                for(int j=num-i-1; j>0; j--)
                {
                    Console.Write(" ");
                }
                for (int j = 0; j < i*2-1; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }

        }

        static void Main(string[] args)
        {
            Console.WriteLine("메인함수 Call");
            int x = 5;

            Console.WriteLine("함수 호출 전 : {0}", x);
            print(ref x);
            Console.WriteLine("함수 호출 후 : {0}", x);

            UpDownCasting(1);
            UpDownCasting((int)3.15);

            Console.WriteLine(Factorial(5));

            one(5);

            Console.WriteLine();

            two(5);

            Console.WriteLine();

            three(5);

            Console.WriteLine();

            four(5);

            
            Cube();
        }

        static void GetAppInfo()
        {
            string name = "Koo";
            int age = 29;
            string appVersion = "1.0";

            Console.WriteLine(name + " is" + age);

            Console.ForegroundColor = ConsoleColor.Green;

            Console.WriteLine("{0} is {1} and Version is {2}", name, age, appVersion);

            Console.ResetColor();

        }

        static void GreetUser()
        {
            Console.WriteLine("What is your name?");

            string input = Console.ReadLine();

            Console.WriteLine("Hello {0}, let's play a game...", input);
        }

        static void PrintColor(ConsoleColor color, string message)
        {
            Console.ForegroundColor = color;

            Console.WriteLine(message);
            Console.ResetColor();

        }
        static void Cube()
        {
            GetAppInfo();

            GreetUser();

            while (true)
            {


                Random random = new Random();

                int correctNum = random.Next(1, 11);


                int guess = 0;

                Console.WriteLine("Guess a number between 1 and 10");

                while (guess != correctNum)
                {
                    string input2 = Console.ReadLine();



                    if (!int.TryParse(input2, out guess))
                    {

                        PrintColor(ConsoleColor.Red,"Please enter an actual number");

                        Console.ResetColor();

                        continue;
                    }

                    guess = Int32.Parse(input2);

                    if (guess != correctNum)
                    {
                        PrintColor(ConsoleColor.Red,"Wrong number, please try again");

                        Console.ResetColor();
                    }
                }

                PrintColor(ConsoleColor.Yellow, "You are correct!");

                Console.ResetColor();

                Console.WriteLine("한번더 하실려면 Y, 끝내실려면 N 를 입력하시오");


                string input3 = Console.ReadLine();
                

                if (input3 == "N")
                {
                    return;
                }else if(input3 == "Y")
                {
                    continue;
                }
                else
                {
                    return;
                }
            }
        }
    }
}
