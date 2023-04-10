#include "Reserve.h"
#include<fstream>

Reserve::Reserve()
{
	string Id, Name, Pwd, day, noon, roomId, status;

	ifstream ifs("reserver.txt", ios::in);

	while (ifs >> Id && ifs >> Name && ifs >> Pwd && ifs >> day && ifs >> noon && ifs >> roomId && ifs >> status)
	{
		string kay, value;
		map<string, string> m;

		m.insert(make_pair("Id", Id));
		m.insert(make_pair("Name", Name));
		m.insert(make_pair("Pwd", Pwd));
		m.insert(make_pair("day", day));
		m.insert(make_pair("noon", noon));
		m.insert(make_pair("roomId", roomId));
		m.insert(make_pair("status", status));

		data.insert(make_pair(Size++, m));
	}

	ifs.close();

	//for (map<int, map<string, string>>::iterator it = data.begin(); it != data.end(); it++)
	//{
	//	cout << it->first << endl;

	//	for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
	//	{
	//		cout << mit->first << ":"
	//			<< mit->second<<" ";
	//	}

	//	cout << endl;
	//}
}

void Reserve::updateReserve()
{
	ofstream ofs("reserver.txt", ios::out);
	for (map<int, map<string, string>>::iterator it = data.begin(); it != data.end(); it++)
	{
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
		{
			ofs <<mit->second <<" ";
		}
		ofs << endl;
	}
	ofs.close();
}
