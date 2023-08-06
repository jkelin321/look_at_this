#include <iostream>
#include <vector>
#include <cmath>


int total_inc_dec(int n);

int main(){

    int user_input{};
    std::cout << "Inter Xth number below 10:" << std::endl;
    std::cin >> user_input;
    std::cout << total_inc_dec(user_input) << std::endl;
//    std::cout << total_inc_dec(5);
//    std::cout << total_inc_dec(7);
//  int n{};
//  n = 49548;
//  std::cout << n << "<-- starting number" << '\n';
//  n = n/10; std::cout << n <<'\n';
//  std::cout << n%10 << '\n';
//  n = n/10; std::cout << n <<'\n';
//  std::cout << n%10 << '\n';
//  n = n/10; std::cout << n <<'\n';
//  n = n/10; std::cout << n <<'\n';
//  n = n/10; std::cout << n <<'\n';
}
  int total_inc_dec(int n){

      if (n  == 0)
          return 1;
      if (n == 1)
          return 10;

      int counter{100};
      std::vector<int> digit_container; // <-- use vector to hold digit 1,2,3,etc.., sorting done on vector after <-- will clear vector and start over on next number
      int ceilng = std::pow(10,n);
      int inc_flag{1};
      int dec_flag{1};
      for(int i{100}; i < ceilng; i++){
          for(int num_div_ops{i}; num_div_ops  > 0;){
              digit_container.push_back(num_div_ops % 10);
              num_div_ops /= 10;
          }
          for(int i{}; i < digit_container.size() - 1; i++){
              if (digit_container.at(i+1) <  digit_container.at(i))
                  inc_flag = 0;
          }
          for(int i{}; i < digit_container.size() - 1; i++){
              if (digit_container.at(i+1) > digit_container.at(i))
                  dec_flag = 0;
          }
          if (inc_flag == 1 || dec_flag ==1)
              counter++;
          digit_container.clear();
          inc_flag = 1; 
          dec_flag = 1;
      }
      return counter;
  }
