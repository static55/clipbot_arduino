// for some reason i need this to fix a linking error..
// probably not required if using the arduino ide..

namespace ros
{
  void normalizeSecNSec(unsigned long& sec, unsigned long& nsec){
    unsigned long nsec_part= nsec % 1000000000UL;
    unsigned long sec_part = nsec / 1000000000UL;
    sec += sec_part;
    nsec = nsec_part;
  }

  Time& Time::fromNSec(long t)
  {
    sec = t / 1000000000;
    nsec = t % 1000000000;
    normalizeSecNSec(sec, nsec);
    return *this;
  }

  Time& Time::operator +=(const Duration &rhs)
  {
    sec += rhs.sec;
    nsec += rhs.nsec;
    normalizeSecNSec(sec, nsec);
    return *this;
  }

  Time& Time::operator -=(const Duration &rhs){
    sec += -rhs.sec;
    nsec += -rhs.nsec;
    normalizeSecNSec(sec, nsec);
    return *this;
  }
}
