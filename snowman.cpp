#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
#include<string>
#include <array>
using namespace std;

namespace ariel{

std::string snowman(int number){

//Test len
const int max = 44444444;
const int min = 11111111;

    if(number > max || number < min){
		throw invalid_argument("This value of namber must between 11111111 - 44444444");
	}


//Test valid
	int my_number = number;
    int stop_check = 0;
	int digit = 0;
    int max_value = 4;
    int min_value = 1;
    const int num_div = 10;

	while(my_number > stop_check){
		digit = (my_number % num_div);
		if(digit < min_value || digit > max_value){
			throw invalid_argument("The value of all digit must between 1-4");
		}
		my_number = my_number / num_div;
	}

	const array<string,4> Hat {"_===_"," ___\n.....","  _\n /_\\"," ___\n(_*_)"};
	const array<string,4> Nose {",",".","_"," "};
	const array<string,4> LeftEye {"(.","(o","(O","(-"};
	const array<string,4> RightEye {".)","o)","O)","-)"};
	const array<string,4> LeftArm {"<","\\","/",""};
	const array<string,4> RightArm {">","/","\\",""};
	const array<string,4> Torso {"( : )","(] [)","(> <)","(   )"};
	const array<string,4> Base {"( : )","(\" \")","(___)","(   )"};

    const int max_index=8;
    int index = 0;
    int num = 0;
    const int len_div_number = 10000000;

    int counter = len_div_number;

    bool flag_up = false;
    bool flag_down = false;
    

    //check hat
    int num_hat = (number / counter);
    const int one_hat = 1;
    const int two_hat = 2;
    const int three_hat = 3;
    const int four_hat = 4;

    //check arm
    const int value_upArm = 2;
    const int value_downArm = 1;
    const int value_downArmTwo = 3;

    string hat;
    string head;
    string stomach;
    string build_snowman;
    string temp_build;

    //name case
    const int case0_hat = 0;
    const int case1_nose = 1;
    const int case2_leftEye = 2;
    const int case3_rightEye = 3;
    const int case4_leftArm = 4;
    const int case5_rightArm = 5;
    const int case6_torso = 6;
    const int case7_base = 7;

while(index < max_index){
    num = (number / counter);

    switch(index){
    
        case(case0_hat):
            hat = Hat.at(num-1) + "\n";
            break;

        case(case1_nose):
            head = Nose.at(num-1);
            break;

        case(case2_leftEye):
            temp_build = LeftEye.at(num-1) + head;
            head = temp_build;
            break;

        case(case3_rightEye):
            head += RightEye.at(num-1);
            break;

        case(case4_leftArm):
            if(num == value_upArm){
            temp_build = LeftArm.at(num-1) + head;
              head = temp_build;
              flag_up = true;
            }else if(num == value_downArm || num == value_downArmTwo){
             stomach = LeftArm.at(num-1);
             flag_down = true;
            }
            break;

        case(case5_rightArm):
          if(num == value_upArm){
            head += RightArm.at(num-1);
            }else if(num == value_downArm || num == value_downArmTwo){
            stomach += RightArm.at(num-1);
            }
            break;

        case(case6_torso):
        if(flag_down){
            stomach.insert(1, Torso.at(num-1));
        }else{
            temp_build = Torso.at(num-1) + stomach;
            stomach = temp_build;
        }
            break;

        case(case7_base):
            if(flag_down || flag_up){
                if(num_hat == one_hat){
                    hat = " _===_";
            }
            if(num_hat == two_hat){
                hat =  "  ___\n .....";
            }
            if(num_hat == three_hat){
                hat = "   _\n  /_\\";
            }
            if(num_hat == four_hat){
                hat = "  ___\n (_*_)";
            }

        if(flag_down){
        build_snowman = hat + "\n ";
        build_snowman +=  head + "\n";
        build_snowman += stomach + "\n";
        build_snowman += " " + Base.at(num-1);
        }
        else if(flag_up){
        build_snowman = hat + "\n";
        build_snowman +=  head + "\n";
        build_snowman += " " + stomach + "\n";
        build_snowman += " " + Base.at(num-1);
        }
        }else{
        build_snowman = hat + head + "\n";
        build_snowman += stomach + "\n";
        build_snowman += Base.at(num-1);
        }
    }
    number = number - (num * counter);
    counter = counter / num_div;
    index++;
   }
   return build_snowman;
}
};