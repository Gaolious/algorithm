#include <bits/stdc++.h>
using namespace std;

int windowId = 0;
struct Rect
{
	int l, t, r, b;
	string str;
	Rect(): l(0), t(0), r(0), b(0) {}
	Rect(int left, int top, int right, int bottom) { l = left; r = right, t = top, b = bottom; }
	bool isArea(int x, int y) const { return l <= x && x <= r && t <= y && y <= b; }
	bool isCloseBox(int x, int y) const { return l <= x && x <= l+24 && t <= y && y <= t+24; }
	bool isZoomBox(int x, int y) const { return r-24 <= x && x <= r && t <= y && y <= t+24; }
	bool isMotionBar(int x, int y) const { return t <= y && y <= t+24 && !isCloseBox(x, y) && !isZoomBox(x, y); }
	bool isDataArea(int x, int y) const { return isArea(x, y) && !isMotionBar(x, y); }
	void move(int x, int y)
	{
		l += x; r += x; t += y; b += y;
	}
};
struct Window
{
	int id;
	Rect pos, oldPos;
	bool isZoomed;
	Window *BeforeZoomPrevWindow;
	Window *prev{}, *next{};
	void remove()
	{
		Window *p = prev, *n = next ;
		if (p) p->next = next ;
		if (n) n->prev = prev ;
	}
	void insert(Window *p, Window *n, Window *node)
	{
		node->prev = p; node->next = n;
		if (p) p->next = node ;
		if (n) n->prev = node ;
	}
	void addNext(Window *node) { insert(this, this->next, node); }
	void addPrev(Window *node) { insert(prev, this, node); }

	Window(int left, int top, int right, int bottom)
	{
		id = windowId++;
		isZoomed = false;
		pos = Rect(left, top, right, bottom);
		oldPos = Rect(0, 0, 1023, 1023);
		BeforeZoomPrevWindow = nullptr;
	}
	void toggleZoom()
	{
		isZoomed = !isZoomed;
		swap(pos, oldPos);
	}
};

ostream &operator<<(ostream &out, const Rect &r) { out << r.l << ", " << r.t << ", " << r.r << ", " << r.b; return out;}

struct Manager
{
	Window *root ;
	int startX = 0, startY = 0;
	bool isInCloseBox = false;
	bool isInZoomBox = false;
	bool isInMotionBar = false;
	bool isMouseDown = false;
	Manager()
	{
		windowId = -1;
		root = new Window(0, 0, 1023, 1023);
		root->prev = root->next = root;
	}
	~Manager()
	{
		while ( root->next != root )
		{
			auto p = root->next;
			p->remove();
			delete p;
		}
		delete root;
	}
	void initialize()
	{
		startX = startY = 0;
		isInCloseBox = false;
		isInZoomBox = false;
		isInMotionBar = false;
		isMouseDown = false;
	}
	void CreateWindow(int left, int top, int right, int bottom)
	{
		auto win = new Window(left, top, right, bottom);
		root->addPrev(win);
		cout << "Created window " << win->id << " at " << win->pos << '\n';
	}
	void Redraw()
	{
		for (auto win = root->next ; win != root ; win = win->next)
			cout << "Window " << win->id << " at " << win->pos << '\n';
	}
	void bringToTop(Window *node)
	{
		node->remove();
		root->addPrev(node);
	}

	void down(int x, int y) {
		isMouseDown = true;
		for (auto win = root->prev ; win != root ; win = win->prev)
		{
			if (win->pos.isArea(x, y)) {
				startX = x;
				startY = y;

				isInCloseBox = win->pos.isCloseBox(x, y);
				isInZoomBox = win->pos.isZoomBox(x, y);
				isInMotionBar = win->pos.isMotionBar(x, y);

				if (!win->isZoomed && isInZoomBox )
					win->BeforeZoomPrevWindow = win->prev;

				bringToTop(win);
				cout << "Selected window " << win->id << '\n';
				return;
			}
		}
	}

	void at(int x, int y) {
		if (!isMouseDown || root->prev->isZoomed ) return;
		if (isInMotionBar) {
			int dx = x - startX, dy = y - startY;
			root->prev->pos.move(dx, dy);
			startX = x;
			startY = y;
			cout << "Moved window " << root->prev->id << " to " << root->prev->pos << "\n";
		}
	}

	void up(int x, int y) {
		if (!isMouseDown ) return;
		if (isInMotionBar) {
			at(x, y);
		} else if (isInCloseBox && root->prev->pos.isCloseBox(x, y)) {
			cout << "Closed window " << root->prev->id << "\n";
			auto p = root->prev;
			p->remove();
			delete p;
		}
		else if (isInZoomBox) {
			auto p = root->prev;
			if ( p->pos.isZoomBox(x, y))
			{
				if ( p->isZoomed && p->BeforeZoomPrevWindow)
				{
					p->remove();
					p->BeforeZoomPrevWindow->addNext(p);
				}
				p->toggleZoom();
				cout << "Resized window " << p->id << " to " << p->pos << "\n";
			}
			p->BeforeZoomPrevWindow = nullptr;
		}
		initialize();
	}
};

void process(int Case) {
	string cmd;
	int left, top, right, bottom, x, y;
	Manager mgr;

	while ( cin >> cmd && cmd != "ZZ" )
	{
		if ( cmd == "CR" )
		{
			cin >> left >> top >> right >> bottom;
			mgr.CreateWindow(left, top, right, bottom);
		}
		else if (cmd == "DN" )
		{
			cin >> x >> y ;
			mgr.down(x, y);
		}
		else if (cmd == "UP" )
		{
			cin >> x >> y ;
			mgr.up(x, y);
		}
		else if (cmd == "AT" )
		{
			cin >> x >> y ;
			mgr.at(x, y);
		}
		else if (cmd == "RE" )
		{
			mgr.Redraw();
		}
	}
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
