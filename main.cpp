#include "passgen.h"

using namespace std;
random_device rnd;
int c,length;
string name;
char chrlst;

int main()
{
  setlocale(LC_ALL,"ru_RU.utf8");
  set("Enter length: ",length);
  set("Enter count: ",c);
  wcout << "Enter charlist(rus,en,num,all): ";
  cin>>noskipws>>chrlst;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');//избавляемся от лишних символов,
  wcout << "Enter filename(or leave blank): "; 	//чтобы не кошмарить следующий поток.
  getline(cin, name);

  if (name.empty()) {

    wcout << '\n';

    switch (chrlst) {
    case 'r':case '1':
      print(wcout, rus);
      break;
    case 'e':case '2':
      print(wcout, en);
      break;
    case 'n':case '3':
      print(wcout, num);
      break;
    default:
      print(wcout, rus, en); //НЕ МЕНЯТЬ ПОРЯДОК!
    		    }

  }else {
try{
      wofstream writer{name}; 
writer.imbue(std::locale(writer.getloc(),new std::codecvt_utf8_utf16<wchar_t>));
      switch (chrlst) {
      case 'r':case '1':
        print(writer, rus);
        break;
      case 'e':case '2':
        print(writer, en);
        break;
      case 'n':case '3':
        print(writer, num);
        break;
      default:
        print(writer, rus, en); //НЕ МЕНЯТЬ ПОРЯДОК!
	writer.close();
    }
}catch(exception&ex){cerr<<"exception"<<ex.what()<<'\n';}
  }
}
