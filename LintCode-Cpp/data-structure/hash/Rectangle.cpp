/* 
820. Rectangle
Difficulty: Medium

http://www.lintcode.com/en/problem/rectangle/

Give a set, if you can find four points that make up a rectangle that is parallel to the coordinate axis and outputs YES or NO.

Notice

The number of points in the set is less than 2000, and the coordinate range is [-10000000,10000000].
Example
Given set = [[0,0],[0,1],[1,1],[1,0]], return YES.

Explanation:
We can find four points that make up a rectangle which is parallel to the coordinate axis.
Given set = [[0,0],[0,1],[1,1],[2,0]], return NO.

Explanation:
We can not find four points that meet the conditions.
*/

///  ANSWER NOT TESTED
bool isRectangle(vector<Point>& points)
{
  if (points.size() < 4) return false;
  
  unordered_set<string> table;
  // create the table
  for(int i = 0; i < points.size(); i++)
  {
    string key = std::to_string(points[i].x) + "," + std::to_string(points[i].y);
    if (table.find(key)==table.end())
    {
      table.insert(key);
    }
  }
  
  // bottom-left + up-right can define a rectangle
  for(int i = 0; i < points.size(); i++)
  {
    for(int j = i; j < points.size(); j++)
    {
  // for each two points, see if the table contains the rest two points to build the rectangle      
      string key = to_string(points[i].x) + "," + to_string(points[j].y);
      if (table.find(key)==table.end()) continue;
      key = to_string(points[j].x) + "," + to_string(points[i].y);
      if (table.find(key)==table.end()) continue;
      return true;
    }
  }
  
  return false;
}

