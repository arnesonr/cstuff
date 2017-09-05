#include <vector>
#include <string>

class MCMCFile{
 public:
  MCMCFile (const std::string filename);
  double getNumColumns() const;
  double getMean(int col) const;
  double getStdDev(int col) const;
 private:
  std::vector<double> _vec;
};
