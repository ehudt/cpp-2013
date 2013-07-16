class Foo {
public:
	Foo GetFoo() const ;
	void SetFoo(Foo foo) ;
	Foo MakeFoo() const ;
};

Foo Foo::GetFoo() const { return *this; }
void Foo::SetFoo(Foo foo) { /*foo = MakeFoo();*/ }
Foo Foo::MakeFoo() const { Foo f; return f; }

int main(void) { 
	Foo f;
	Foo g = f.GetFoo();
	f.SetFoo(g);
	g = f.MakeFoo();
	return 0;
}