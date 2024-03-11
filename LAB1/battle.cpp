#include <cstdio>
#include <cstdlib>
int main(){
    system("g++ rand_input.cpp -o rand_input");
    system("g++ check_input.cpp -o check_input");
    system("g++ solution_3.cpp -o solution3");
    system("g++ solution_2.cpp -o solution2");
    system("g++ solution_1.cpp -o solution1");
    for(int i =0 ; i < 1; i ++){
        system("./rand_input > input.txt");
        // if(system("./check_input < rand.in")!=0){
        //     printf("invalid input!\n");
        //     break;
        // }
        // system("./solution1 < input.txt > 1.out");
        system("./solution2 < input.txt > 2.out");
        system("./solution3 < input.txt > 3.out");
        if (system("diff 2.out 3.out") != 0) {
            printf("2, 3 different output!\n");
        } else if (system("diff 2.out 3.out") == 0) {
            printf("2, 3 same output!\n");
        }
        if (system("diff 1.out 3.out") != 0) {
            printf("1,3 different output!\n");
        } else if (system("diff 2.out 3.out") == 0) {
            printf("1,3 same output!\n");
        }

        }//     break;

}
