/***********************************************************************
 * Module:  tecnique.h
 * Author:  David
 * Modified: четверг, 22 но€бр€ 2018 г. 01:06:22
 * Purpose: Declaration of the class tecnique
 ***********************************************************************/

#if !defined(__ClassDiagram_1_tecnique_h)
#define __ClassDiagram_1_tecnique_h

class tecnique
{


public:

	tecnique();					//default
	tecnique(int,int);		//initialisation
	tecnique(const tecnique&);		//copy
	~tecnique();					//destructor

   void fix_problem(void);
   void hold_sems(void);
   void repair_equip(void);
   void equip_lines_for_prototype(void);
   void check_equip(void);
   bool operator ==(tecnique s1)   //перевантаженн€ оператора пор≥вн€нн€
   {
	   if (s1.worked_years == worked_years)
	   {
		   return true;
	   }
	   return false;
   }

   bool operator !=(tecnique s1)   //перевантаженн€ оператора пор≥вн€нн€ (запереченн€)
   {
	   if (s1.worked_years == worked_years)
	   {
		   return false;
	   }
	   return true;
   }
   bool operator <(tecnique obj1)
   {
	   if (obj1.worked_years > worked_years)
	   {
		   return true;
	   }
	   else
	   {
		   return false;
	   }
   }

  bool operator >(tecnique obj1)
   {
	  if (worked_years> obj1.worked_years)
	   {
		   return true;
	   }
	   else
	   {
		   return false;
	   }
   }
  
protected:
private:
   int worked_years;
   int qualification;

};

#endif