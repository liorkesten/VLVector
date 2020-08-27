

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#define DEF_SIZE 4
void printVLV(const VLVector<int,DEF_SIZE>& a)
{
	for (int i=0;i<(int)a.size();i++)
	{
		std::cout<<"a["<<i<<"]="<<a[i]<<std::endl;
	}
}
void checkEqualOP1() // b is static, a is dynm
{
	VLVector<int,DEF_SIZE> a;
	for (int i=0;i<20;i++)
	{
		a.push_back(i);
	}
	VLVector<int,DEF_SIZE> b;
	for (int i=0;i<2;i++)
	{
		b.push_back(i);
	}
	assert(b!=a);
	b=a;
	assert(b==a);
}
void checkEqualOP2() // b is dynm, a is dynm
{
	VLVector<int,DEF_SIZE> a;
	for (int i=0;i<20;i++)
	{
		a.push_back(i);
	}
	VLVector<int,DEF_SIZE> b;
	for (int i=0;i<15;i++)
	{
		b.push_back(i);
	}
	assert(b!=a);
	b=a;
	assert(b==a);

}
void checkEqualOP3() // b is dynm, a is stat
{
	VLVector<int,DEF_SIZE> a;
	for (int i=0;i<3;i++)
	{
		a.push_back(i);
	}
	VLVector<int,DEF_SIZE> b;
	for (int i=0;i<15;i++)
	{
		b.push_back(i);
	}
	assert(b!=a);
	b=a;
	assert(b==a);
}
void checkEqualOP4() // b is stat, a is stat
{
	VLVector<int,DEF_SIZE> a;
	for (int i=0;i<3;i++)
	{
		a.push_back(i);
	}
	VLVector<int,DEF_SIZE> b;
	for (int i=0;i<2;i++)
	{
		b.push_back(i);
	}
	assert(b!=a);
	b=a;
	assert(b==a);
}
void checkEqOp()
{
	checkEqualOP1();
	checkEqualOP2();
	checkEqualOP3();
	checkEqualOP4();
}
void checkCompOp()
{
	VLVector<int,DEF_SIZE> a;
	for (int i=0;i<3;i++)
	{
		a.push_back(i);
	}
	VLVector<int,DEF_SIZE> b;
	for (int i=0;i<3;i++)
	{
		b.push_back(i);
	}
	assert(a==b);
	a.clear();
	for (int i=0;i<20;i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i=0;i<20;i++)
	{
		b.push_back(i);
	}
	assert(a==b);
	a.clear();
	for (int i=0;i<20;i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i=0;i<5;i++)
	{
		b.push_back(i);
	}
	assert(!(a==b));
	a.clear();
	for (int i=0;i<5;i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i=0;i<20;i++)
	{
		b.push_back(i);
	}
	assert(!(a==b));
	a.clear();
	for (int i=0;i<20;i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i=0;i<20;i++)
	{
		if (i==5)
		{
			b.push_back(20);
		}
		else
		{
			b.push_back(i);
		}
	}
	assert(!(a==b));
	a.clear();
	for (int i=0;i<20;i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i=0;i<15;i++)
	{
		b.push_back(i);
	}
	assert(!(a==b));
	a.clear();
	for (int i=0;i<2;i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i=0;i<3;i++)
	{
		b.push_back(i);
	}
	assert(!(a==b));
}
void checkNonCompOp()
{
	VLVector<int,DEF_SIZE> a;
	for (int i=0;i<3;i++)
	{
		a.push_back(i);
	}
	VLVector<int,DEF_SIZE> b;
	for (int i=0;i<3;i++)
	{
		b.push_back(i);
	}
	assert(!(a!=b));
	a.clear();
	for (int i=0;i<20;i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i=0;i<20;i++)
	{
		b.push_back(i);
	}
	assert(!(a!=b));
	a.clear();
	for (int i=0;i<20;i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i=0;i<5;i++)
	{
		b.push_back(i);
	}
	assert((a!=b));
	a.clear();
	for (int i=0;i<5;i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i=0;i<20;i++)
	{
		b.push_back(i);
	}
	assert((a!=b));
	a.clear();
	for (int i=0;i<20;i++)
	{
		a.push_back(i);
	}
	b.clear();
	for (int i=0;i<20;i++)
	{
		if (i==5)
		{
			b.push_back(20);
		}
		else
		{
			b.push_back(i);
		}
	}
	assert((a!=b));
}
void checkItr()
{
	VLVector<int, DEF_SIZE> a;
	std::vector<int> b;
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	int j=0;
	for (auto &cur:a)
	{
		assert(cur==b[j]);
		j++;
	}
	j=0;
	a.clear();
	b.clear();
	for (int i = 0; i < 3; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	for (auto &cur:a)
	{
		assert(cur==b[j]);
		j++;
	}
	j=0;
	a.clear();
	b.clear();
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	for (const auto &cur:a)
	{
		assert(cur==b[j]);
		j++;
	}
	j=0;
	a.clear();
	b.clear();
	for (int i = 0; i < 3; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	for (const auto &cur:a)
	{
		assert(cur==b[j]);
		j++;
	}
	j=0;
	a.clear();
	b.clear();
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	auto cura = a.begin();
	auto curb = b.begin();
	curb++;
	cura++;
	assert(*cura==*curb);
	curb += 5;
	cura+=5;
	assert(*cura==*curb);
	auto curb2 = curb + 10;
	auto cura2 = cura + 10;
	assert(*cura2==*curb2);
	a.clear();
	b.clear();
	for (int i = 0; i < 20; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	const VLVector<int,DEF_SIZE> f(a);
	auto ita=f.begin();
	auto itb=b.begin();
	assert(*ita==*itb);
	a.clear();
	b.clear();
	for (int i = 0; i < 3; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	const VLVector<int,DEF_SIZE> r(a);
	ita=r.begin();
	itb=b.begin();
	assert(*ita==*itb);
	a.clear();
	b.clear();
	for (int i = 0; i < 10; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	auto it2a=a.begin();
	auto it2b=b.begin();
	it2a=it2a+5;
	it2b=it2b+5;
	assert(*it2a==*it2b);
	it2a=-3+it2a;
	it2b=-3+it2b;
	assert(*it2a==*it2b);
	const VLVector<int,DEF_SIZE> vlv(a);
	auto it3a=vlv.begin();
	auto it3b=b.begin();
	it3a=it3a+5;
	it3b=it3b+5;
	assert(*it3a==*it3b);
	it3a=-3+it3a;
	it3b=-3+it3b;
	assert(*it3a==*it3b);





}
void insert1()
{
	VLVector<int,DEF_SIZE> a;
	std::vector<int> b;
	for (int i=0;i<20;i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	auto ita=a.begin();
	auto itb=b.begin();
	ita+=6;
	itb+=6;
	assert(*a.insert(ita,300)==*b.insert(itb,300));
	for (unsigned long i=0;i<20;i++){assert(a[i]==b[i]);}
	b.clear();
	a.clear();
	for (int i=0;i<3;i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	ita=a.begin();
	itb=b.begin();
	ita+=2;
	itb+=2;
	assert(*a.insert(ita,300)==*b.insert(itb,300));
	for (unsigned long i=0;i<3;i++){assert(a[i]==b[i]);}
	b.clear();
	a.clear();
	for (int i=0;i<4;i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	ita=a.begin();
	itb=b.begin();
	ita+=3;
	itb+=3;
	assert(*a.insert(ita,300)==*b.insert(itb,300));
	for (unsigned long i=0;i<4;i++){assert(a[i]==b[i]);}
	b.clear();
	a.clear();
	for (int i=0;i<7;i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	ita=a.begin();
	itb=b.begin();
	ita+=3;
	itb+=3;
	assert(*a.insert(ita,300)==*b.insert(itb,300));
	for (unsigned long i=0;i<7;i++){assert(a[i]==b[i]);}

}
void insert1Const()
{
	std::vector<int> b;
	VLVector<int,DEF_SIZE> a;
	for (int i=0;i<20;i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	auto ita=a.cbegin();
	auto itb=b.cbegin();
	ita+=6;
	itb+=6;
	assert(*a.insert(ita,300)==*b.insert(itb,300));
	for (unsigned long i=0;i<20;i++){assert(a[i]==b[i]);}
	a.clear();
	b.clear();
	for (int i=0;i<2;i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	ita=a.cbegin();
	itb=b.cbegin();
	ita+=2;
	itb+=2;
	assert(*a.insert(ita,300)==*b.insert(itb,300));
	for (unsigned long i=0;i<2;i++){assert(a[i]==b[i]);}
	a.clear();
	b.clear();
	for (int i=0;i<4;i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	ita=a.cbegin();
	ita+=3;
	itb=b.cbegin();
	itb+=3;
	assert(*a.insert(ita,300)==*b.insert(itb,300));
	for (unsigned long i=0;i<4;i++){assert(a[i]==b[i]);}
	a.clear();
	b.clear();
	for (int i=0;i<7;i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	ita=a.cbegin();
	ita+=3;
	itb=b.cbegin();
	itb+=3;
	assert(*a.insert(ita,300)==*b.insert(itb,300));
	for (unsigned long i=0;i<7;i++){assert(a[i]==b[i]);}

}
void checkBuilder()
{
	std::vector<int> a;
	for (int i=0;i<3;i++)
	{
		a.push_back(i);
	}
	VLVector<int,DEF_SIZE> b(a.begin(),a.end());
	for (unsigned long i=0;i<3;i++){assert(a[i]==b[i]);}
	a.clear();
	for (int i=0;i<15;i++)
	{
		a.push_back(i);
	}
	VLVector<int,DEF_SIZE> c(a.begin(),a.end());
	for (unsigned long i=0;i<15;i++){assert(a[i]==c[i]);}
}

void insert2()
{
	std::vector<int> a;
	for (int i=0;i<10;i++)
	{
		a.push_back(i);
	}
	VLVector<int,DEF_SIZE> b;
	std::vector<int> ref;
	for (int i=11;i<20;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto iterb=b.begin();
	auto iteref=ref.begin();
	iterb+=5;
	iteref+=5;
	assert(*b.insert(iterb,a.begin(),a.end())==*ref.insert(iteref,a.begin(),a.end()));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}

	a.clear();
	b.clear();
	ref.clear();
	for (int i=1;i<3;i++)
	{
		a.push_back(i*30);
	}
	for (int i=0;i<4;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	iterb=b.begin();
	iterb+=2;
	iteref=ref.begin();
	iteref+=2;
	assert(*b.insert(iterb,a.begin(),a.end())==*ref.insert(iteref,a.begin(),a.end()));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}
	a.clear();
	b.clear();
	ref.clear();
	for (int i=1;i<10;i++)
	{
		a.push_back(i*30);
	}
	for (int i=0;i<4;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	iterb=b.begin();
	iterb+=2;
	iteref=ref.begin();
	iteref+=2;
	assert(*b.insert(iterb,a.begin(),a.end())==*ref.insert(iteref,a.begin(),a.end()));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}
	ref.clear();
	a.clear();
	b.clear();
	for (int i=1;i<2;i++)
	{
		a.push_back(i*30);
	}
	for (int i=0;i<10;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	iterb=b.begin();
	iterb+=2;
	iteref=ref.begin();
	iteref+=2;
	assert(*b.insert(iterb,a.begin(),a.end())==*ref.insert(iteref,a.begin(),a.end()));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}



}
void constInsert2()
{
	std::vector<int> a;
	for (int i=0;i<10;i++)
	{
		a.push_back(i);
	}
	VLVector<int,DEF_SIZE> b;
	std::vector<int> ref;
	for (int i=11;i<20;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto iterb=b.cbegin();
	iterb+=5;
	auto iteref=ref.cbegin();
	iteref+=5;
	assert(*b.insert(iterb,a.begin(),a.end())==*ref.insert(iteref,a.begin(),a.end()));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}
	ref.clear();
	a.clear();
	b.clear();
	for (int i=1;i<3;i++)
	{
		a.push_back(i*30);
	}
	for (int i=0;i<4;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto iterb2=b.cbegin();
	(iterb2)+=2;
	auto iteref2=ref.cbegin();
	(iteref2)+=2;
	assert(*b.insert(iterb2,a.begin(),a.end())==*ref.insert(iteref2,a.begin(),a.end()));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}
	ref.clear();
	a.clear();
	b.clear();
	for (int i=1;i<10;i++)
	{
		a.push_back(i*30);
	}
	for (int i=0;i<4;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto iterb3=b.cbegin();
	(iterb3)+=2;
	auto iteref3=ref.cbegin();
	(iteref3)+=2;
	assert(*b.insert(iterb3,a.begin(),a.end())==*ref.insert(iteref3,a.begin(),a.end()));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}
	ref.clear();
	a.clear();
	b.clear();
	for (int i=1;i<2;i++)
	{
		a.push_back(i*30);
	}
	for (int i=0;i<10;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto iterb4=b.cbegin();
	(iterb4)+=2;
	auto iteref4=ref.cbegin();
	(iteref4)+=2;
	assert(*b.insert(iterb4,a.begin(),a.end())==*ref.insert(iteref4,a.begin(),a.end()));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}


}
void erase()
{
	std::vector<int> ref;
	VLVector<int,DEF_SIZE> b;
	for (int i=0;i<15;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto firstb=b.begin()+5;
	auto lastb=b.begin()+10;
	auto firstref=ref.begin()+5;
	auto lastref=ref.begin()+10;
	assert(*b.erase(firstb,lastb)==*ref.erase(firstref,lastref));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}
	ref.clear();
	b.clear();
	for (int i=0;i<15;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	firstb=b.begin()+1;
	lastb=b.begin()+13;
	firstref=ref.begin()+1;
	lastref=ref.begin()+13;
	assert(*b.erase(firstb,lastb)==*ref.erase(firstref,lastref));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}
	ref.clear();
	b.clear();
	for (int i=0;i<4;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	firstb=b.begin()+1;
	lastb=b.begin()+3;
	firstref=ref.begin()+1;
	lastref=ref.begin()+3;
	assert(*b.erase(firstb,lastb)==*ref.erase(firstref,lastref));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}
	ref.clear();
	b.clear();
	for (int i=0;i<10;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	firstb=b.begin()+1;
	lastb=b.end();
	firstref=ref.begin()+1;
	lastref=ref.end();
	assert(*b.erase(firstb,lastb)==*ref.erase(firstref,lastref));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}
	ref.clear();
	b.clear();
	for (int i=0;i<10;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	firstb=b.begin()+1;
	firstref=ref.begin()+1;
	assert(*b.erase(firstb,firstb)==*ref.erase(firstref,firstref));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}



}
void constErase()
{
	std::vector<int> ref;
	VLVector<int,DEF_SIZE> b;
	for (int i=0;i<15;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto firstb=b.cbegin()+5;
	auto lastb=b.cbegin()+10;
	auto firstref=ref.cbegin()+5;
	auto lastref=ref.cbegin()+10;
	assert(*b.erase(firstb,lastb)==*ref.erase(firstref,lastref));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}
	ref.clear();
	b.clear();
	for (int i=0;i<15;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto first2b=b.cbegin()+1;
	auto last2b=b.cbegin()+13;
	auto first2ref=ref.cbegin()+1;
	auto last2ref=ref.cbegin()+13;
	assert(*b.erase(first2b,last2b)==*ref.erase(first2ref,last2ref));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}
	ref.clear();
	b.clear();
	for (int i=0;i<4;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto first3b=b.cbegin()+1;
	auto last3b=b.cbegin()+3;
	auto first3ref=ref.cbegin()+1;
	auto last3ref=ref.cbegin()+3;
	assert(*b.erase(first3b,last3b)==*ref.erase(first3ref,last3ref));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}


}
void eraseSingle()
{
	std::vector<int> ref;
	VLVector<int,DEF_SIZE> b;
	for (int i=0;i<15;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto firstb=b.begin()+5;
	auto firstref=ref.begin()+5;
	assert(*b.erase(firstb)==*ref.erase(firstref));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}
	ref.clear();
	b.clear();
	for (int i=0;i<5;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	firstb=b.begin()+2;
	firstref=ref.begin()+2;
	assert(*b.erase(firstb)==*ref.erase(firstref));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}
	ref.clear();
	b.clear();
	for (int i=0;i<4;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	firstb=b.begin()+1;
	firstref=ref.begin()+1;
	assert(*b.erase(firstb)==*ref.erase(firstref));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}
	ref.clear();
	b.clear();
	for (int i=0;i<4;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	firstb=b.end()-1;
	firstref=ref.end()-1;
	assert(*b.erase(firstb)==*ref.erase(firstref));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}



}
void constEraseSingle()
{
	std::vector<int> ref;
	VLVector<int,DEF_SIZE> b;
	for (int i=0;i<15;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto firstb=b.cbegin()+5;
	auto firstref=ref.cbegin()+5;
	assert(*b.erase(firstb)==*ref.erase(firstref));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}
	ref.clear();
	b.clear();
	for (int i=0;i<15;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto first2b=b.cbegin()+1;
	auto first2ref=ref.cbegin()+1;
	assert(*b.erase(first2b)==*ref.erase(first2ref));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}
	ref.clear();
	b.clear();
	for (int i=0;i<4;i++)
	{
		b.push_back(i);
		ref.push_back(i);
	}
	auto first3b=b.cbegin()+1;
	auto first3ref=ref.cbegin()+1;
	assert(*b.erase(first3b)==*ref.erase(first3ref));
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(ref[i]==b[i]);}

}
void sort()
{
	std::vector<int> a={5,8,3,7,5,9,543,321,765,21,6};
	VLVector<int,DEF_SIZE> b(a.begin(),a.end());
	std::sort(b.begin(),b.end());
	std::sort(a.begin(),a.end());
	for (unsigned long i=0;i<(unsigned long)b.size();i++){assert(a[i]==b[i]);}

}
void forEach()
{
	std::vector<int> a={5,8,3,7,5,9,543,321,765,21,6};
	VLVector<int,DEF_SIZE> b(a.begin(),a.end());
	int sumB=0,sumA=0;
	std::for_each(b.begin(),b.end(),[&sumB](int x)->int { return sumB+=x;});
	std::for_each(a.begin(),a.end(),[&sumA](int x)->int { return sumA+=x;});
	assert(sumA==sumB);
}
void checkAt()
{
	std::vector<int> a={5,8,3,7,5,9,543,321,765,21,6};
	VLVector<int,DEF_SIZE> b(a.begin(),a.end());
	try { std::cout<<b.at(-5)<<std::endl;}
	catch (...) { }
	try { std::cout<<b.at(500)<<std::endl;}
	catch (...) { }
	for (unsigned long i=0;i<(unsigned long)a.size();i++){assert(a.at(i)==b.at(i));}

}
void checkConstructors()
{
	std::vector<int> a={1,2,3,4,5,6,7,8,9};
	VLVector<int,DEF_SIZE> b(a.begin(),a.end());
	for (unsigned long i=0;i<(unsigned long)a.size();i++){assert(a[i]==b[i]);}
	VLVector<int ,DEF_SIZE> c(b);
	for (unsigned long i=0;i<(unsigned long)a.size();i++){assert(c[i]==a[i]);}
	std::vector<int> a2={1,2,3};
	VLVector<int,DEF_SIZE> b2(a2.begin(),a2.end());
	for (unsigned long i=0;i<(unsigned long)a2.size();i++){assert(a2[i]==b2[i]);}
	VLVector<int ,DEF_SIZE> c2(b);
	for (unsigned long i=0;i<(unsigned long)a2.size();i++){assert(a2[i]==c2[i]);}
}
void checkCap()
{
	//--------------------- constructor --------------------
	std::vector<int> b;
	for (int i = 0; i < 2; i++) {b.push_back(i);}
	VLVector<int,DEF_SIZE> a1(b.begin(),b.end());
	assert(a1.capacity()==DEF_SIZE);
	for (int i = 0; i < 3; i++) {b.push_back(i);}
	VLVector<int,DEF_SIZE> a2(b.begin(),b.end());
	assert(a2.capacity()==7);
	for (int i = 0; i < 4; i++) {b.push_back(i);}
	VLVector<int,DEF_SIZE> a3(b.begin(),b.end());
	assert(a3.capacity()==12);
	//---------- push back-------------------
	VLVector<int,DEF_SIZE> a;
	for (int i = 0; i < 2; i++) {a.push_back(i);}
	assert(a.capacity()==DEF_SIZE);
	for (int i = 0; i < 2; i++) {a.push_back(i);}
	assert(a.capacity()==DEF_SIZE);
	for (int i = 0; i < 2; i++) {a.push_back(i);}
	assert(a.capacity()==7);
	a.push_back(1);
	assert(a.capacity()==7);
	a.push_back(1);
	assert(a.capacity()==12);
	//--------------------- insert --------------------
	a.clear();
	for (int i = 0; i < 6; i++) {a.push_back(i);}
	b.clear();
	for (int i = 0; i < 10; i++) {b.push_back(i);}
	auto it=a.begin()+2;
	a.insert(it,b.begin(),b.end());
	assert(a.capacity()==19);
	//----------------- erase -----------------------
	it=a.begin()+2;
	auto it2=a.begin()+10;
	a.erase(it,it2);
	assert(a.capacity()==19);
	it=a.begin();
	it2=a.begin()+5;
	a.erase(it,it2);
	assert(a.capacity()==DEF_SIZE);


}
int LiorTests()
{
	checkConstructors();
	checkNonCompOp();
	checkCompOp();
	checkEqOp();
	checkItr();
	insert1();
	insert1Const();
	checkBuilder();
	insert2();
	constInsert2();
	erase();
	constErase();
	eraseSingle();
	constEraseSingle();
	sort();
	forEach();
	checkAt();
	checkCap();
	std::cout<<"-------------------------test "
			   "passed!-----------------------------------"<<std::endl;


}
