#define mp make_pair
map< pair<int,int>, int > dis;
int main(){
	string s;
	cin >> s;
	int n = s.length();
	int x = 0, y = 0;
	dis[mp(x,y)] = 0;
	if(dis.find(mp(x+1,y)) == dis.end()) 
		dis[mp(x+1,y)] = 1;
	if(dis.find(mp(x,y+1)) == dis.end()) 
		dis[mp(x,y+1)] = 1;
	if(dis.find(mp(x-1,y)) == dis.end()) 
		dis[mp(x-1,y)] = 1;
	if(dis.find(mp(x,y-1)) == dis.end()) 
		dis[mp(x,y-1)] = 1;
	for(int i=0;i<n;i++){
		if(s[i] == 'L') x--;
		else if(s[i] == 'R') x++;
		else if(s[i] == 'U') y--;
		else y++;
		// cout << x << " " << y << " " << (dis.find(mp(x,y)) != dis.end()) << " " << dis[mp(x,y)] << "\n";
		if(dis.find(mp(x,y)) != dis.end() && dis[mp(x,y)] < i+1){
			cout << "BUG"; return 0;
		}
		dis[mp(x,y)] = i+1;
		if(dis.find(mp(x+1,y)) == dis.end()) dis[mp(x+1,y)] = i+2;
		if(dis.find(mp(x,y+1)) == dis.end()) dis[mp(x,y+1)] = i+2;
		if(dis.find(mp(x-1,y)) == dis.end()) dis[mp(x-1,y)] = i+2;
		if(dis.find(mp(x,y-1)) == dis.end()) dis[mp(x,y-1)] = i+2;
	}
	cout << "OK";
	return 0;
}