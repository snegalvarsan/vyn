//#include "vyn/vyn.cpp"
#include "file_updater.cpp"

using namespace vyn;

/*enum class library_privacy{
    SHARED,STATIC
};*/

namespace cmake_writer{
    string cmakelists(){
        ret "CMakeLists__.txt";
    }
    string cmake_version(){
        ret "CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)";
    }

class cmake_writer_class{
    public:
    void message(string content){
        file f;
        string cmake_content = f.read(cmake_writer::cmakelists());
        string add_message_content = "\nmessage(\"" + content + "\")";
        cmake_content = cmake_content + add_message_content;
        f.write(cmake_writer::cmakelists(),cmake_content);
        print "message_written." line;
    }
    void project_name(string project_name_){
        file f;
        string cmake_content = f.read(cmake_writer::cmakelists());
        string add_project_name_content = "\nPROJECT(" + project_name_ + ")";
        cmake_content = cmake_content + add_project_name_content;
        f.write(cmake_writer::cmakelists(),cmake_content);
        print "project_name="<<project_name_ line;
    }
    void add_executable(string exe_name,string exe_file){
        file f;
        string cmake_content = f.read(cmake_writer::cmakelists());
        string add_executable_content = "\nADD_EXECUTABLE(" + exe_name + " " + exe_file + ")";
        cmake_content = cmake_content + add_executable_content;
        f.write(cmake_writer::cmakelists(),cmake_content);
        print "added_executable." line;

    }
    void target_link_libraries(string target_link_library_name){
        file f;
        string cmake_content = f.read(cmake_writer::cmakelists());
        string add_target_link_libraries_content = "\nTARGET_LINK_LIBRARIES(" + target_link_library_name + " ${PROJECT_NAME})";
        cmake_content = cmake_content + add_target_link_libraries_content;
        f.write(cmake_writer::cmakelists(),cmake_content);
        print "added_target_link_libraries." line;
    }
    void add_library(string folder_name){
        file f;
        string cmake_content = f.read(cmake_writer::cmakelists());
        //library_privacy lb = library_privacy::SHARED;
        string add_library_content = "\nADD_LIBRARY(${PROJECT_NAME} ";
        string shared = "SHARED";
        string static_ = "STATIC";
        print_line;
        print "Enter" line;
        print "1. for shared" line;
        print "2. for static" line;
        print ":" line;
        string value;
        sinput(value);
        if(value == "1"){
            add_library_content = add_library_content + " " + shared + " ";
        }
        else if(value == "2"){
            add_library_content = add_library_content + " " + static_ + " ";
        }
        else{
            print "Invalid Entry, going with default = STATIC." line;
            add_library_content = add_library_content + " " + static_ + " ";
        }
        print_line;
        add_library_content = add_library_content + folder_name+ ")";
        cmake_content = cmake_content + add_library_content;
        f.write(cmake_writer::cmakelists(),cmake_content);
        print "added_library." line;
    }
    void custom_write(string content){
        file f;
        string cmake_content = f.read(cmake_writer::cmakelists());
        cmake_content = cmake_content + "\n" +  content;
        f.write(cmake_writer::cmakelists(),cmake_content);
        print "custom content written." line;
    }
    void target_include_directories(string target_include_directory_name,string target_include_directory){
        file f;
        string cmake_content = f.read(cmake_writer::cmakelists());
        string add_target_include_directories_content = "\nTARGET_INCLUDE_DIRECTORIES(" + target_include_directory_name;
        string private_ = "PRIVATE";
        string public_ = "PUBLIC";
        print_line;
        print "Enter" line;
        print "1. for private" line;
        print "2. for public" line;
        print ":" line;
        string value;
        sinput(value);
        if(value == "1"){
            add_target_include_directories_content = add_target_include_directories_content + " " + private_ + " ";
        }
        else if(value == "2"){
            add_target_include_directories_content = add_target_include_directories_content + " " + public_ + " ";
        }
        else{
            print "Invalid Entry, going with default = PRIVATE." line;
            add_target_include_directories_content = add_target_include_directories_content + " " + private_ + " ";
        }
        print_line;
        add_target_include_directories_content = add_target_include_directories_content + " " + target_include_directory;
        cmake_content = cmake_content + add_target_include_directories_content+")";
        f.write(cmake_writer::cmakelists(),cmake_content);
        print "added_target_include_directories." line;
    }
    void add_subdirectory(string dir_name){
        file f;
        string cmake_content = f.read(cmake_writer::cmakelists());
        string add_subdirectory_content = "\nADD_SUBDIRECTORY(" + dir_name + ")";
        cmake_content = cmake_content + add_subdirectory_content;
        f.write(cmake_writer::cmakelists(),cmake_content);
        print "added_subdirectory." line;
    }
};

void cmake_file_printer(){
        print_line;
        print_line;
        print cmake_writer::cmakelists() line;
        print "==============================================" line;
        file f;
        print f.read(cmake_writer::cmakelists()) line;
        print_line;
        print "==============================================" line;
        print_line;
        print "Enter EOF to exit:" line;
        print "Enter" line;
        print "1.add_library" line;
        print "2.add_executable" line;
        print "3.target_link_libraries" line;
        print "4.message" line;
        print "5.target_include_directories" line;
        print "6.add_subdirectory" line;
        print "7.write customized command" line;
        print_line;
        print "'rm' to remove last line" line;
        print ":" line;
}

void cmake_writer_execute(){
    print_line;
    print "Welcome" line;
    print "Creating a "<<cmake_writer::cmakelists()<<" file" line;
    cmake_writer::cmake_writer_class cmk;
    file f;
    f.write(cmake_writer::cmakelists(),cmake_writer::cmake_version());
    print "Successfully created" line;
    print "Enter the project name:" line;
    string inp;
    sinput(inp);
    cmk.project_name(inp);
    while(true){
        cmake_writer::cmake_file_printer();
        string value;
        sinput(value);
        
        
        if(lower(value)== "eof"){
            break;
        }
        else if(value == "1"){
            print_line;
            print "Enter library directory name:" line;
            string dir_name;
            sinput(dir_name);
            cmk.add_library(dir_name);
        }
        else if(value == "2"){
            print_line;
            print "Enter executable file's name:" line;
            string exe_name;
            sinput(exe_name);
            print "Enter the file name which has to be made as an exe file:" line;
            string exe_file;
            sinput(exe_file);
            cmk.add_executable(exe_name,exe_file);
        }
        else if(value == "3"){
            print_line;
            print "Enter the target link library name:" line;
            string dir_name;
            sinput(dir_name);
            cmk.target_link_libraries(dir_name);
        }
        else if(value == "4"){
            print_line;
            print "Enter the message:" line;
            string message;
            sinput(message);
            cmk.message(message);
        }
        else if(value == "5"){
            print_line;
            print "Enter the target include directory's name:" line;
            string dir_name;
            sinput(dir_name);
            print "Enter the directory path:" line;
            string dir_path;
            sinput(dir_path);
            cmk.target_include_directories(dir_name,dir_path);
        }
        else if(value == "6"){
            print_line;
            print "Enter sub-directory name:" line;
            string dir_name;
            sinput(dir_name);
            cmk.add_subdirectory(dir_name);
        }
        else if(value == "7"){
            print_line;
            print "Enter the customized_command:" line;
            string message;
            sinput(message);
            cmk.custom_write(message);
        }
        else if(lower(value) == "rm"){
            file_updater::remove_last_line(cmake_writer::cmakelists());
        }
        else{
            print "Invalid entry." line;
        }
    }
}

}


int main(){
    cmake_writer::cmake_writer_execute();
    done;
}