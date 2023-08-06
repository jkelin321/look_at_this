
#include <vector>
#include <cmath>

unsigned long long total_inc_dec(unsigned int n) {
  
      if (n  == 0)
          return 1;
      if (n == 1)
          return 10;

//       int counter{100};
      unsigned long long counter{100};
      std::vector<int> digit_container;
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

  //return 0ULL;
}
