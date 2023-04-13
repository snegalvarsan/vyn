#include "vyn.cpp"

using namespace vyn;

namespace file_updater{
    void add_next_line(string filename,string additional_content){
        file f;
        string content = f.read(filename);
        content = content + additional_content;
        f.write(filename,content);
    }
    void remove_last_line(string filename){
        file f;
        string content = f.read(filename);
        char *p;
        p = string_to_char_array(content);
        int count=0;
        int n=0;
        forloop(i,content.length()){
            if(*(p+i)=='\n'){
                count++;
                n = count;
            }
        }
        if(n==1){
            print "Removed the last line viz. first line." line;
            file f;
            f.write(filename,"");
        }
        else{
        count = 0;
        string last_line;
        int k;
        forloop(i,content.length()){
            if(*(p+i)=='\n'){
                count++;
                int j;
                if((n-1)==count){
                    print "Removed=" line;
                    k = i+1;
                    for(j=i+1;j<content.length();j++){
                        last_line = last_line + *(p+j);
                    }
                    
                }
            }
        }
        print last_line line;
        string updated_content;
        int g;
        for(g=0;g<k-1;g++){
            updated_content = updated_content + *(p+g);
        }
        p=NULL;
        print "=====" line;
        print updated_content line;
        print "=====" line;
        f.write(filename,updated_content);
    }
    }
    void display_file(string filename){
        file f;
        print_line;
        print "=============================" line;
        print filename line;
        print "=============================" line;
        print f.read(filename);
        print "=============================" line;
        
    }
    void remove_many_lines(string filename,int number_of_lines){//segmentation fault
        file f;
        string content = f.read(filename);
        char *p;
        p = string_to_char_array(content);
        int count=0;
        int n=0;
        forloop(i,content.length()){
            if(*(p+i)=='\n'){
                count++;
                n = count;
            }
        }
        if(n==1){
            print "Removed the last line viz. first line." line;
            f.write(filename,"");
        }
        else{
        count = 0;
        string last_line;
        int k;
        int remover=0;
        while(true){
            if(remover==number_of_lines){
                break;
                }
            else{
                forloop(i,content.length()){
                if(*(p+i)=='\n'){
                count++;
                int j;
                if((n-1)==count){
                    print "Removed=" line;
                    k = i+1;
                    for(j=i+1;j<content.length();j++){
                        last_line = last_line + *(p+j);
                        }
                    
                    }
                }
                }
                print last_line line;
                string updated_content;
                int g;
                for(g=0;g<k-1;g++){
                    updated_content = updated_content + *(p+g);
                }
                p=NULL;
                print "=====" line;
                print updated_content line;
                print "=====" line;
                f.write(filename,updated_content);
                }
            remover++;
            
            }
        
        }

}
}

int main(){
    string content;
    string filename;
    //string option;
    while(true){

        print "Enter the file name to proceed:" line;
        sinput(filename);
        if(filename == ""){
            print "Invalid entry." line;
        }
        else{
            while(true){
            file_updater::display_file(filename);
            print "Enter eof to exit:" line;
            print "Enter -rm to remove last line" line;
            print ":" line;
            sinput(content);
            if(lower(content) == "-rm"){
                file_updater::remove_last_line(filename);
            }
            else if(lower(content) == "eof"){
                break;
            }
            else{
                file_updater::add_next_line(filename,content);
            }
            }
            break;
        }
    }
}

//ok
