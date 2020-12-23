
int main() {  
  
    int counter = 0;
    int test = 0;
    
    while(counter < 5) {
      ++counter;
      if((counter & 1) != 0) {
          test = 1;
      } else {
          test = 0;
      }
    }
    
    return 0;
}
  