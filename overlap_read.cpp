#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
int main(){

  // Open catalog file and skip header line.
  std::ifstream cat("/Users/coyote_arnie/Desktop/LSST/lsstSimCatalog.dat");
  std::string header;
  std::getline(cat,header);

  std::vector<Ellipse> galaxies;
  std::cout << ":)" << std::endl;
  // Estimate i-band cut for requested density.
  double icut = 1.40095*std::log(1.22248e6*(-density));
  // Loop over catalog entries.
  long id;
  int lines(0);
  double ra,dec,u,g,r,i,z,y,redshift,a_bulge,b_bulge,a_disk,b_disk,absmag_r_total;
  while(cat.good()) {
    cat >> id >> ra >> dec >> u >> g >> r >> i >> z >> y
        >> redshift >> a_bulge >> b_bulge >> a_disk >> b_disk >> absmag_r_total;
    //std::cout << id << std::endl;
    if(!cat.good()) {
        std::cout << ':(' << std::endl;
        break;
    }
    //if(!cat.good()) break;
    lines++;
    // Does this pass our magnitude limit?
    if(i > icut) continue;
    // Convert (ra,dec) to arcmins relative to the catalog field center.
    double x = (ra - 0.028)*60*180/pi;
    double y = (dec - 0.089)*60*180/pi;
    // Is this object within our field.
    if(x*x + y*y > fieldRadius*fieldRadius) continue;
    // Create this galaxy.
    double ratio = 1;
    double phi = 0;
    if(!circular) {
        // Ignore galaxies with no disk component
        if(a_disk == 0) continue;
        // The catalog is roughly flat in ratio = b_disk/a_disk
        ratio = b_disk/a_disk;
        phi = random->getUniform()*2*pi;
    }
    // Calculate the galaxy major and minor radii in arcmins.
    double rminor,rmajor;
    if(galaxyRadius < 0) {
        rminor = b_disk/60.;
    }
    else {
        rminor = std::sqrt(galaxyArea*ratio/pi)/60.;
    }
    rmajor = rminor/ratio;
    if(psfSizeSq > 0) {
        rminor = std::sqrt(rminor*rminor + psfSizeSq);
        rmajor = std::sqrt(rmajor*rmajor + psfSizeSq);
    }
    if(galaxyRadius < 0) {
        rminor *= -galaxyRadius;
        rmajor *= -galaxyRadius;
    }
    // Add this galaxy to the field.
  galaxies.push_back(Ellipse(x,y,rmajor,rminor,phi));
  std::cout << "galaxies" << galaxies.size() << std::endl;
  std::cout << "Lines: " << lines << std::endl;
  }

  return 0;
}
