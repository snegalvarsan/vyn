#include "vyn.cpp"

using namespace vyn;


class ffprobe{
    public:
    string probe_get_as_json(string video_file,string stream,string av){
        string ffprobe_json_content = "ffprobe -v error " + video_file +" -show_entries stream="+stream+ " -select_streams "+av+" -print_format json";
        print ffprobe_json_content line;
        ret get_system_write(ffprobe_json_content);
    }
};

class ffplay{
    public:
    void play(string video_file){
            string ffplay_play_content = "ffplay -v error -i " + video_file;
            system_write(ffplay_play_content);
        }
};

class ffmpeg{
    public:
        void trim(string video_file,int start_time,int end_time,string output_video_file){
            string ffmpeg_trim_content = "ffmpeg -y -v error -i "+ video_file + " -ss " + int_to_string(start_time) + " -to " + int_to_string(end_time) + " " + output_video_file;
            system_write(ffmpeg_trim_content);
        }
        void merge(string text_file_name,string output_video_file){
            string ffmpeg_merge_content = "ffmpeg -y -v error -f concat -i " + text_file_name + " " + output_video_file;
            system_write(ffmpeg_merge_content);
        }
        void scale(string video_file,int height,int width,string output_video_file){
            string ffmpeg_scaling_content = "ffmpeg -y -v error -i " + video_file + " -vf " + "scale=" + int_to_string(height)+":"+int_to_string(width)+ " " + output_video_file;
            system_write(ffmpeg_scaling_content);
        }
        void generate_thumbnail(string video_file,int time,int scale_height,int scale_width,string output_image_file){
            string ffmpeg_thumbnail_content = "ffmpeg -y -v error -i " + video_file + " -ss " + int_to_string(time) + " -vframes 1 -vf scale="+int_to_string(scale_height)+":"+int_to_string(scale_width) + " " + output_image_file;
            system_write(ffmpeg_thumbnail_content); 
        }

};

 // color remover code -> file ffmpeg -i input.mp4 -vf eq=gamma_b=0.5 output.mp4

void ffmpeg_trim(){
        ffmpeg fmg;
        string video_file,output_video_file;
        int start_time,end_time;
        print "\nEnter video file name:" line;
        sinput(video_file);
        print "Enter output file name:" line;
        sinput(output_video_file);
        print "Enter trim start time(in s):" line;
        input start_time;
        print "Enter trim end time(in s):" line;
        input end_time;
        fmg.trim(video_file,start_time,end_time,output_video_file);
}

void ffmpeg_scale(){
        ffmpeg fmg;
        string video_file,output_video_file;
        int height,width;
        print "\nEnter video file name:" line;
        sinput(video_file);
        print "Enter output file name:" line;
        sinput(output_video_file);
        print "Enter height:" line;
        input height;
        print "Enter width:" line;
        input width;
        fmg.scale(video_file,height,width,output_video_file);
}

void ffmpeg_merge(){
        ffmpeg fmg;
        string text_file_name;
        string output_video_file;
        string text_file_cont="";
        string text_inp;
        print_line;
        while(true){
            print "Enter video file name to be added for merging\n[enter EOF to stop adding videos]:" line;
            sinput(text_inp);
            if(upper(text_inp)=="EOF"){
                break;
            }
                text_file_cont = text_file_cont + "file \'"+text_inp + "\'";
                text_file_cont = text_file_cont + "\n";       
            print_line;
            print_line;
        }
        file f;
        print "Enter the name of the text file:" line;
        sinput(text_file_name);
        f.write(text_file_name,text_file_cont);
        print "Enter the output video file name:" line;
        sinput(output_video_file);
        fmg.merge(text_file_name,output_video_file);
}

void ffmpeg_generate_thumbnail(){
        ffmpeg fmg;
        string video_file;
        int time;
        int scale_width;
        int scale_height;
        string output_image_file;
        print_line;
        print "Enter the name of the video file:" line;
        sinput(video_file);
        print "Enter the time of the video which has to be captured for thumbnail(in s):" line;
        input time;
        print "Enter the scale height of the video:" line;
        input scale_height;
        print "Enter the scale width of the video:" line;
        input scale_width;
        print "Enter the name of the output image file:" line;
        sinput(output_image_file);
        fmg.generate_thumbnail(video_file,time,scale_height,scale_width,output_image_file);

}


void ffplay_runner(){
    ffplay fply;
    print_line;
    string video_file;
    print "Enter video/image file name:" line;
    sinput(video_file);
    fply.play(video_file);
}

void ffmpeg_runner(){
    ffmpeg fmg;
    print 
    "\nEnter"
    "\n1.trim"
    "\n2.scale"
    "\n3.merge"
    "\n4.generate thumbnail\n:" 
    line;
    string inp;
    sinput(inp);
    if(inp=="1"){
        ffmpeg_trim();
    }
    else if(inp=="2"){
        ffmpeg_scale();
    }
    else if(inp=="3"){
        ffmpeg_merge();
    }
    else if(inp=="4"){
        ffmpeg_generate_thumbnail();
    }
    else{
        print_line;
        print "Invalid entry" line;
    }
}

void ffmpeg_run(){
    while(true){
    print_line;
    print 
    "Enter"
    "\n\n1.ffmpeg"
    "\n\n2.ffplay"
    "\n\n3.ls"
    "\n\n4.exit"
    "\n\n:" 
    line;
    string value;
    sinput(value);
    if(value == "1"){
        ffmpeg_runner();
    }
    else if(value == "2"){
        ffplay_runner();
    }
    else if(value == "3"){
        print_line;
        print_line;
        print get_system_write("ls") line;
    }
    else if(value == "4"){
        print_line;
        print "Thank you" line;
        break;
    }
    else{
        print_line;
        print "Invalid input." line;
    }

    }
    
}



int main(){
    
    ffmpeg_run();
    done;
}

