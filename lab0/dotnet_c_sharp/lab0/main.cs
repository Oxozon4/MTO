using System;
using System.IO;

namespace lab0
{
    class Hello {         
	static void my_printf(string format_string, string param){
		for(int i=0;i<format_string.Length;i++){
			if((format_string[i] == '#') && (format_string[i+1] == 'k')){
				Console.Write(param);
				i++;
			}else{
				Console.Write(format_string[i]);
			}
		}
		Console.Write("\n");
	}
        static void Main(string[] args)
        {
	    string format_string;
	    while ((format_string = Console.ReadLine()) != null)
	    {
		string param = Console.ReadLine();
		my_printf(format_string,param);
	    }
        }
    }
}
