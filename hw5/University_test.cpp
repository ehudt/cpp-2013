#include "University.h"
#include <assert.h>

void main(void){
	University uni = University::GetObj();
	uni.CancelLecture("spanish is canceled");
	assert(uni.GetLastMessage()=="spanish is canceled");
	uni.RaisePrice(500);
	assert(uni.GetPrice()==500);
}
