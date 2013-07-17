template <int N>
struct fact{
	static const int value = N * fact<N-1>::value;
};

template <>
struct fact<0>{
	static const int value = 1;
};

int main(void) {
	fact<50000>::value;
	return 0;
}