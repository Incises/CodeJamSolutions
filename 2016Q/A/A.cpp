#include <iostream>
#include <string>

using namespace std;
int total;
int line;
bool handled[10];

void inc(int foo) {
   while (foo) {
      handled[foo % 10] = true;
      foo /= 10;
   }
}

int main()
{
   cin >> total;
   for (int i=0; i<total; ++i)
   {
      cin >> line;
      cout << "Case #" << i+1 << ": ";
      if (!line)
      {
         cout << "INSOMNIA" << endl;
      } else
      {
         for (int ctr=0; ctr<sizeof(handled); ctr++)
         {
            handled[ctr]=false;
         }
         for(int j=1; ; j++)
         {
            inc(j*line);
            int opt = 0;
            for (int k=0; k < 10; k++)
               opt += int(handled[k]);
            if(opt==10)
            {
               //if(!handled[j])
               cout << j*line << endl;
               break;
            }

         }
      }
   }
   return 0;
}
