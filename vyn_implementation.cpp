#include "vyn.cpp"

using namespace vyn;

int hello(){
    ret 1;
}

int main(){
    print "A" line;
    print "hello" comma "world" line;
    print oscheck<<"-ok" line;
    print_line;
    string a = "1";
    print int_to_string(string_to_int(a)+1) line;
    print upper("a") line;
    for_loop(i,3){
        print "ok" loopspace;
    }
    file f;
    f.write("file.txt","hello");
    string content = f.read("file.txt"); // hello
    char *p;
    string h = "haha";
    p = string_to_char_array(h);
    for_loop(j,h.length()){
        print *(p+j);
    }
    print_line;
    print reverse_string(h) line;
    int inp;
    input inp;
    string inps;
    string_input(inps);
    print "hello function return value = "<<hello() line;
    print "Random number = "<<random_number(5) line;
    print char_to_ascii('a') line;
    print "Palindrome, if yes 1, else 0:\n"<<palindrome("madam") line;
    print "a" tab "b" line;
    ui32 a1 = 1;
    ui32 b1 = 2;
    ui32 c1 = add(a1,b1);
    print c1 line;
    system_write("ls"); // for LINUX
    print get_system_write("ls") line;
    done;
}
