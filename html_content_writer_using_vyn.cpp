#include<iostream>
#include "vyn.cpp"

using namespace vyn;


string content_closer_hint_adder(string closer_content_hint_add){
    string content_closer;
    return content_closer =  "<p>"+closer_content_hint_add+"</p></body></html>";

}

string loading_content_wrapper(string hint,string common_content){
        string content_closer =  "<p>"+content_closer_hint_adder(hint)+"</p></body></html>";
        string htmlcreator = common_content + content_closer;
        ret htmlcreator;
}

string loading_common_content(string url){

    string css_file = "loading_design.css";
    string timedelay = "3";
    string title = "Game_content";
    string common_content = "<html><head><meta http-equiv="
    "\"refresh\" content=\""+timedelay+"; URL="+url+"\" /><title>"+title+"</title>"
    "<link rel=\"stylesheet\" href = \""+css_file+"\">"
    "</head><body><h2>Loading...</h2><br><p>Please wait</p><br>";
    ret common_content;
}

string loading(string url,string hint_type){

    string car_hint = "Hint: Buy expensive cars to reduce difficulty while travelling.(Or else just pay 50 Integs for taxi fare to travel ;))";
    string casino_hint = "Hint: Buying food in hotel improves health, while bidding in casinos are risky yet a great platform to make huge profits.";
    string gym_hint = "Hint: Working out in Gym increases your reputation.";
    string park_hint = "Hint: Parks are a perfect hangout place during date missions.";
    string stadium_hint = "Hint: Just like the casinos, you can place a bid for your favorite team. Also this is an ideal spot to hangout during date missions.";
    string house_hint = "Hint: Save your progress in safe house to not lose your track of progress.";
    string industry_hint = "Hint: Industries are a great way to gain stable flow of income with each passing day.";
    string common_hint = "Hint: Besides Industries and Houses, you can also buy the gym, park, stadium, casinos etc. Each place has its own way of easing your gameplay.";
    string ammu_nation_hint = "Hint: Buy weapons to reduce difficulty in missions.";
    string hospital_hint = "Hint: You'll be respawned in the Hospital if you die in the game.";
    string random_missions_hint = "Hint: Random missions are a great way to make money by being a Bounty hunter. Higher the reputation, higher the bounty cash .";
    string theatres_hint = "Hint: You can watch movies for just 100 Integs! Have a nice day...!";
    string missions_hint = "Hint: Get weapons from Ammu nation to reduce difficulty. If you fail in a mission, your reputation will decrease.";
    

    if (hint_type == "car"){
        ret loading_content_wrapper(car_hint,loading_common_content(url));
        
    }
    else if(hint_type == "casino"){
        ret loading_content_wrapper(casino_hint,loading_common_content(url));
    }
    else if(hint_type == "gym"){
        ret loading_content_wrapper(gym_hint,loading_common_content(url));
    }
    else if(hint_type == "park"){
        ret loading_content_wrapper(park_hint,loading_common_content(url));
    }
    else if(hint_type == "stadium"){
        ret loading_content_wrapper(stadium_hint,loading_common_content(url));
    }
    else if(hint_type == "house"){
        ret loading_content_wrapper(house_hint,loading_common_content(url));
    }
    else if(hint_type == "industry"){
        ret loading_content_wrapper(industry_hint,loading_common_content(url));
    }
    else if(hint_type == "common"){
        ret loading_content_wrapper(common_hint,loading_common_content(url));
    }
    else if(hint_type == "ammu_nation"){
        ret loading_content_wrapper(ammu_nation_hint,loading_common_content(url));
    }
    else if(hint_type == "hospital"){
        ret loading_content_wrapper(hospital_hint,loading_common_content(url));
    }
    else if(hint_type == "random_missions"){
        ret loading_content_wrapper(random_missions_hint,loading_common_content(url));
    }
    else if(hint_type == "theatres"){
        ret loading_content_wrapper(theatres_hint,loading_common_content(url));
    }
    else if(hint_type == "missions"){
        ret loading_content_wrapper(missions_hint,loading_common_content(url));
    }
    ret 0;
}

void file_write_load(string loading_,string next_file_name,string hint_type){
    file f;
    f.write(loading_+next_file_name,loading(next_file_name,hint_type));
}

void write_loading_content(){
    string loading_ = "loading_";
    file_write_load(loading_,"car.html","car");
    file_write_load(loading_,"casino.html","casino");
    file_write_load(loading_,"gym.html","gym");
    file_write_load(loading_,"park.html","park");
    file_write_load(loading_,"stadium.html","stadium");
    file_write_load(loading_,"house_1.html","house");
    file_write_load(loading_,"house_2.html","house");
    file_write_load(loading_,"house_3.html","house");
    file_write_load(loading_,"house_4.html","house");
    file_write_load(loading_,"house_5.html","house");
    file_write_load(loading_,"house_6.html","house");
    file_write_load(loading_,"industry_1.html","industry");
    file_write_load(loading_,"industry_2.html","industry");
    file_write_load(loading_,"industry_primary_1.html","industry");
    file_write_load(loading_,"industry_primary_2.html","industry");
    file_write_load(loading_,"industry_primary_3.html","industry");
    file_write_load(loading_,"ammu_nation_1.html","ammu_nation");
    file_write_load(loading_,"ammu_nation_2.html","ammu_nation");
    file_write_load(loading_,"main_menu.html","common");
    file_write_load(loading_,"bank.html","common");
    file_write_load(loading_,"police_station.html","common");
    file_write_load(loading_,"court.html","common");
    file_write_load(loading_,"hospital.html","hospital");
    file_write_load(loading_,"airport.html","common");
    file_write_load(loading_,"random_missions.html","random_missions");
    file_write_load(loading_,"theatres.html","theatres"); 
    file_write_load(loading_,"missions.html","missions");
}

void loading_content_writer(){
    write_loading_content();
    print "loading content created" line;
    
}

int main(){
    loading_content_writer();

}
