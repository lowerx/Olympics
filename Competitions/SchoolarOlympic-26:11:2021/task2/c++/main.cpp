#include <iostream>
#include <string>

using namespace std;

int main ()
{
  string input, number;
  int i, a, result;
  int input_nums[100];
  int secondary_nums[100];
  string input_signs;
  string secondary_signs;
  bool is_number = false;
  int ind = 0;

  input_signs = "";

  getline (cin, input);

  for (i = 0; i < 100; i++)
    {
      input_nums[i] = 0;
      secondary_nums[i] = 0;
    }

  for (i = 0; i < input.length (); i++)
    {
      if (input[i] == '*')
	{
	  input_signs += '*';
	  input_nums[ind] = stoi (number);
	  number = "";
	  ind++;
	}
      else if (input[i] == '/')
	{
	  input_signs += "/";
	  input_nums[ind] = stoi (number);
	  number = "";
	  ind++;
	}
      else if (input[i] == '+')
	{
	  input_signs += "+";
	  input_nums[ind] = stoi (number);
	  number = "";
	  ind++;
	}
      else if (input[i] == '-')
	{
	  input_signs += "-";
	  input_nums[ind] = stoi (number);
	  number = "";
	  ind++;
	}
      else
	{
	  number += input[i];
	  if (i == (input.length () - 1))
	    {
	      input_nums[ind] = stoi (number);
	      number = "";
	    }
	}
    }

  ind = 0;
  is_number = false;
  int inumber;

  for (i = 0; i < input_signs.length (); i++)
    {
      if ((input_signs[i] == '*') || (input_signs[i] == '/'))
	{
	  if (input_signs[i] == '*')
	    {
	      if (is_number)
		{
		  inumber *= input_nums[i + 1];
		}
	      else
		inumber = input_nums[i] * input_nums[i + 1];
	    }
	  else
	    {
	      if (is_number)
		{
		  inumber /= input_nums[i + 1];
		}
	      else
		inumber = input_nums[i] / input_nums[i + 1];
	    }
	  is_number = true;
	}
      else
	{
	  secondary_signs += input_signs[i];
	  if (is_number)
	    {
	      secondary_nums[ind] = inumber;
	      is_number = false;
	      inumber = 0;
	    }
	  else
	    {
	      secondary_nums[ind] = input_nums[i];
	    }
	  if (i == (input_signs.length () - 1))
	    {
	      secondary_nums[ind + 1] = input_nums[i + 1];
	    }
	  ind++;
	}
    }
  if (inumber != 0)
    {
      is_number = false;
      secondary_signs += input_signs[i];
      secondary_nums[ind] = inumber;
      inumber = 0;
    }

  result = secondary_nums[0];
  for (i = 0; i < secondary_signs.length (); i++)
    {
      if (secondary_signs[i] == '+')
	{
	  result += secondary_nums[i + 1];
	}
      else
	{
	  result -= secondary_nums[i + 1];
	}
    }

  cout << result << endl;

  return 0;
}
