#include "check_ping.cpp"

using namespace vyn;

int main(){
    while(true){
    string a;
    print_line;
    print "Enter the ip address to check connection" line;
    print "[enter \'stop\' to stop]" line;
    print ":" line;
    sinput(a);
    if(upper(a)=="STOP"){
        break;
    }
    else{
    print_ping(a);
    }
    }
    done;
}
