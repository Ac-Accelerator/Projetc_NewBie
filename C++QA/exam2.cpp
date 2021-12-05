#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
struct Process
{
	string pName, pDesciption;
	int pID, pPriority, pState = 1, pCPU;
};
bool compare_priority(Process, Process);
void p_initial(Process &, string, int, int, int, int, string);
void show(Process);
main()
{
	Process list[4];
	p_initial(list[0], "chrome.exe", 101, 10, 1, 3, "google chrome");
	p_initial(list[1], "360.exe", 102, 7, 1, 1, "360安全卫士");
	p_initial(list[2], "QQ.exe", 103, 5, 1, 4, "腾讯QQ");
	p_initial(list[3], "CPPIDE.exe", 104, 3, 1, 20, "CFree5.0");
	sort(list, list + 4, compare_priority);
	for (int i = 0; i < 4; i++)
	{
		if (list[i].pState == 1)
		{
			list[i].pState = 2;
			while (list[i].pCPU)
			{
				list[i].pCPU--, list[i].pPriority -= 3;
				for (int t = 1; t < 4; t++)
				{
					if (list[t].pState == 1)
					{
						list[t].pPriority++;
					}
				}
			}
			list[i].pState = 3;
		}
	}
	cout << "邓宇哲202112140";
}
bool compare_priority(Process a, Process b)
{
	return a.pPriority > b.pPriority;
}
void p_initial(Process &a, string name, int pid, int ppriority, int pstate, int pcpu, string pdescrib)
{
	a.pName = name;
	a.pID = pid;
	a.pPriority = ppriority;
	a.pState = pstate;
	a.pCPU = pcpu;
	a.pDesciption = pdescrib;
}
void show(Process a)
{
	cout << "pName=" << a.pName << ' '
		 << "plD=" << a.pID << ' '
		 << "pPriority=" << a.pPriority << ' '
		 << "pState=" << a.pState << ' '
		 << "pCPU=" << a.pCPU << ' '
		 << "pDescription=" << a.pDesciption << endl;
}
