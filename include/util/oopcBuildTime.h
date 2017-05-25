#ifndef D_oopcBuildTime_H
#define D_oopcBuildTime_H

///////////////////////////////////////////////////////////////////////////////
//
//  oopcBuildTime is responsible for recording and reporting when
//  this project library was built
//
///////////////////////////////////////////////////////////////////////////////

class oopcBuildTime
  {
  public:
    explicit oopcBuildTime();
    virtual ~oopcBuildTime();
    
    const char* GetDateTime();

  private:
      
    const char* dateTime;

    oopcBuildTime(const oopcBuildTime&);
    oopcBuildTime& operator=(const oopcBuildTime&);

  };

#endif  // D_oopcBuildTime_H
