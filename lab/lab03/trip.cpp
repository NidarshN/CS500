#include <iostream>
#include <vector>
#include <iomanip>
#include "trip.h"

float moneyEqualizer(std::vector<float> expenses){
  float total = 0.00f;
  int n = expenses.size();
  
  for(int i=0; i < n; ++i){
    total += expenses[i];
  }

  float avg_total = total / n;
  float positive_difference = 0.00f;
  float negative_difference = 0.00f;
  
  float total_change = 0.00f;

  for(int i=0; i < n; ++i){
    if(expenses[i] > avg_total){
      positive_difference += (long) ((expenses[i] - avg_total) * 100.0) / 100.0;
    }else{
      negative_difference += (long) ((avg_total - expenses[i]) * 100.0) / 100.0;
    }
  }


  if(positive_difference > negative_difference){
    return positive_difference;
  }else{
    return negative_difference;
  }

}
