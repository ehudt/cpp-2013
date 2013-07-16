class NoCtor{
public:
	NoCtor(const NoCtor& other) {}
};

int main() {
	NoCtor nc;
	return 0;
}