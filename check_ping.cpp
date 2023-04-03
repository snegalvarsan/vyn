#include "vyn.cpp"

using namespace vyn;

bool get_data_for_ping(string content){
    char *p;
    p = string_to_char_array(content);
    int count=0;
    for_loop(i,content.length()){
        if(count==1){
            if(isdigit(*(p+i+1))){
                p=NULL;
                ret true;
            }
            else{
                p=NULL;
                ret false;
            }
        }
        if(*(p+i) == '\n'){
            //print *(p+i)<<" in position "<< int_to_string(i) line;
            count++;
        }
    }
    p=NULL;
    ret false;
}

bool check_connection(string ip_address){
    string content = get_system_write("ping " + ip_address + " -c 1");
    if(get_data_for_ping(content)){
        ret true;  
    }
    else{
        ret false;
    }
}

void print_ping(string ip){
    print_line;
    print ip line;
    print check_connection(ip) line;
}


