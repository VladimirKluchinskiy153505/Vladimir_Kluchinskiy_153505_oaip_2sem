using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task1
{
    internal class Program
    {
        static int Main(string[] args)
        {
            Zhes apple = new Zhes("Apple");
            Occupant human = new Occupant("Vasia","Ivanov", Rates.preferential);
            human.service_collection.Add(new Service(Services.gas));
            human.service_collection.Add(new Service(Services.electricity));

            Occupant human1 = new Occupant("Olga", "Antonenko", Rates.middle);
            human1.service_collection.Add(new Service(Services.internet));
            human1.service_collection.Add(new Service(Services.heating));
            human1.service_collection.Add(new Service(Services.water));

            Occupant human2 = new Occupant("Alex", "Geargiev", Rates.low);
            human2.service_collection.Add(new Service(Services.television));
            human2.service_collection.Add(new Service(Services.electricity));
            human1.service_collection.Add(new Service(Services.gas));

            Occupant human3 = new Occupant("Katy", "Perry", Rates.high);
            human3.service_collection.Add(new Service(Services.gas));
            human3.service_collection.Add(new Service(Services.electricity));

            Occupant human4 = new Occupant("Rihanna", "Andreykina", Rates.preferential);
            human4.service_collection.Add(new Service(Services.water));
            human4.service_collection.Add(new Service(Services.electricity));

            apple.occupant_collection.Add(human);
            apple.occupant_collection.Add(human1);
            apple.occupant_collection.Add(human2);
            apple.occupant_collection.Add(human3);
            apple.occupant_collection.Add(human4);
            for (int i = 0; i < apple.occupant_collection.Count; ++i)
            {
                 Occupant cur_ocup= apple.occupant_collection[i];
                Console.WriteLine(cur_ocup.name+" "+cur_ocup.surname+" "+cur_ocup.Rate);
                Console.WriteLine("His services:");
                for(int j = 0; j < cur_ocup.service_collection.Count; ++j)
                {
                    Service serv = cur_ocup.service_collection[j];
                    Console.Write(serv.Get() + " ");
                }
                Console.WriteLine();
                Console.WriteLine("His common payement:");
                Console.WriteLine(cur_ocup.CalculatePayment());
                Console.WriteLine();
            }
            //int k = 0;
            //while (k < apple.occupant_collection.Count)
            //{
            //    Console.WriteLine( apple.occupant_collection.Current().name);
            //    apple.occupant_collection.Next();
            //    ++k;
            //}
            //Console.WriteLine();
            //int q = 0;
            //apple.occupant_collection.RemoveCurrent();
            //while (q< apple.occupant_collection.Count)
            //{
            //    Console.WriteLine(apple.occupant_collection.Current().name);
            //    apple.occupant_collection.Next();
            //    ++q;
            //}
            while (true)
            {
                Console.WriteLine();
                Console.WriteLine("0.See All");
                Console.WriteLine("1.Reset");
                Console.WriteLine("2.SeeNext");
                Console.WriteLine("3.SeeCurrent");
                Console.WriteLine("4.Count");
                Console.WriteLine("5.Add");
                Console.WriteLine("6.Remove(Surname)");
                Console.WriteLine("7.RemoveCurrent");
                Console.WriteLine("8.CommontPayment of Current Person");
                Console.WriteLine("9.Exit");
                int num;
                Int32.TryParse(Console.ReadLine(), out num);
                Console.WriteLine();
                if(num == 0)
                {
                    for(int i = 0; i < apple.occupant_collection.Count; ++i)
                    {
                        Console.WriteLine(apple.occupant_collection.Current().name+" "+ apple.occupant_collection.Current().surname);
                         apple.occupant_collection.Next();
                    }
                }
                else if (num == 1)
                {
                    apple.occupant_collection.Reset();
                }else if (num == 2)
                {
                    apple.occupant_collection.Next();
                    Console.WriteLine(apple.occupant_collection.Current().name+" "+apple.occupant_collection.Current().surname);
                }
                else if (num == 3)
                {
                    Console.WriteLine(apple.occupant_collection.Current().name+" "+ apple.occupant_collection.Current().surname+":");
                    for (int j = 0; j < apple.occupant_collection.Current().service_collection.Count; ++j)
                    {
                        Console.WriteLine(apple.occupant_collection.Current().service_collection.Current().Get());
                        apple.occupant_collection.Current().service_collection.Next();
                    }
                }
                else if (num == 4)
                {
                    Console.WriteLine("Amount of Occupants: "+ apple.occupant_collection.Count);
                }
                else if (num == 5)
                {
                    Console.WriteLine();
                    string name, surname;
                    Rates rate;
                    Console.WriteLine("Enter name");
                    name=Console.ReadLine();
                    Console.WriteLine("Enter surname");
                    surname = Console.ReadLine();
                    Console.WriteLine("Enter number of Rate:\n 1.Low,2.Preferential,3.Middle,4.High");
                    int num_rate;
                    Int32.TryParse(Console.ReadLine(),out num_rate);
                    switch (num_rate)
                    {
                        case 1: rate = Rates.low;break;
                        case 2: rate = Rates.preferential;break;
                        case 3:rate = Rates.middle;break;
                        case 4:rate = Rates.high;break;
                        default:rate=Rates.high;break;
                    }
                    Occupant person = new Occupant(name, surname, rate);
                    Console.WriteLine("Enter Servises this Person use");
                    Console.WriteLine("1.gas 2.heating 3.electricity 4.water 5.internet 6.television 7.Enough");
                    int num_serv=0;
                    while (num_serv!=7)
                    {
                        Int32.TryParse(Console.ReadLine(), out num_serv);
                        switch (num_serv)
                        {
                            case 1:person.service_collection.Add(new Service(Services.gas)); break;
                            case 2: person.service_collection.Add(new Service(Services.heating)); break;
                            case 3: person.service_collection.Add(new Service(Services.electricity)); break;
                            case 4: person.service_collection.Add(new Service(Services.water)); break;
                            case 5: person.service_collection.Add(new Service(Services.internet)); break;
                            case 6: person.service_collection.Add(new Service(Services.television)); break;
                            default: break;
                        }
                    }
                    apple.occupant_collection.Add(person);
                }
                else if (num == 6)
                {
                    Console.WriteLine("Enter name of person you want to delete");
                    string name=Console.ReadLine();
                    Console.WriteLine("Enter surname");
                    string surname=Console.ReadLine();
                    Occupant temp=new Occupant(name, surname);
                    int q=apple.occupant_collection.Remove(temp);
                    if (q == 1) { Console.WriteLine("Element has been deleted!"); }
                    else
                    {
                        Console.WriteLine("Element hasn't been found!");
                    }
                }
                else if (num == 7)
                {
                    apple.occupant_collection.RemoveCurrent();
                }
                else if (num == 8)
                {
                    Console.WriteLine(apple.occupant_collection.Current().name+" :"+apple.occupant_collection.Current().CalculatePayment());
                }
                else
                {
                    return 0;
                }
            }
            Console.ReadKey();
            return 0;
        }
    }
}
