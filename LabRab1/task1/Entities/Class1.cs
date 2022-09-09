using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task1
{
    enum Services
    {
        gas = 100,
        heating = 200,
        electricity = 300,
        water = 400,
        internet = 500,
        television = 600
    }
    enum Rates
    {
        low = 1,
        preferential,
        middle,
        high
    }
    class Service : IEquatable<Service>
    {
        public Service(Services service)
        {
            this.service = service;
        }
        Services service;
        public ref Services Get() { return ref service; }
        public void Set(Services service) { this.service = service; }
        public bool Equals(Service other)
        {
            return this.service == other.service;
        }
    }
    class Occupant : IEquatable<Occupant>
    {
        public Occupant(string name,string surname,Rates rate)
        {
            this.name = name;
            this.surname = surname;
            this.rate= rate;
            service_collection = new MyCustomCollection<Service>();
        }
        public Occupant(string name, string surname)// for comparing
        {
            this.name = name;
            this.surname = surname;
        }
        public string name;
       public string surname;
        Rates rate;
        public Rates Rate { get { return rate; } set { rate = value; } }
       public MyCustomCollection<Service> service_collection;
        public bool Equals(Occupant other)
        {
            return (this.surname == other.surname) && (this.name==other.name);
        }
        public double CalculatePayment()
        {
            double sum = 0;
            for (int i = 0; i < service_collection.Count; i++)
            {
                sum += (int)service_collection[i].Get() * (int)rate;
            }
            return sum;
        }
    }
    class Zhes
    {
        public Zhes(string name) 
        { this.name = name;
            occupant_collection=new MyCustomCollection<Occupant>();
        }
       public string name;
      public MyCustomCollection<Occupant> occupant_collection;
    }
}
