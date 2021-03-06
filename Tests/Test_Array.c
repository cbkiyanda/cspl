#include <stdio.h>

#include "CSPL_Test.h"
#include "../CSPL/Array/CSPL_Array.h"


int main(void) {
  {
    double d1[5] = {2,3.4, 5.6, 4.5, 3.1};
    double d2[5] = {4.5, 2.3, 3.4, 1.0, 4.5};
    double answer[5] = {6.5, 5.7, 9.0, 5.5, 7.6};
    double out[5];
    long i;
    CSPL_Array_add(d1, d2, out, 5);
    for (i=0;i<5;i++) {
      printf("CSPL_Array_add[%ld]=%lf  %lf\n", i, out[i], answer[i]);
      assert_float_test(out[i], answer[i], 1e-5);
    }

  }
  {
    double d1[5] = {2,3.4, 5.6, 4.5, 3.1};
    double d2[5] = {4.5, 2.3, 3.4, 1.0, 4.5};
    double answer[5] = {-2.5, 1.1, 2.2, 3.5, -1.4};
    double out[5];
    long i;
    CSPL_Array_subtract(d1, d2, out, 5);
    for (i=0;i<5;i++) {
      printf("CSPL_Array_subtract[%ld]=%lf  %lf\n", i, out[i], answer[i]);
      assert_float_test(out[i], answer[i], 1e-5);
    }
  }
  {
    double d1[5] = {2,   3.4, 5.6, 4.5, 3.1};
    double d2[5] = {4.5, 2.3, 3.4, 1.0, 4.5};
    double answer[5] = {9.0, 7.82, 19.04, 4.5, 13.95};
    double out[5];
    long i;
    CSPL_Array_multiply(d1, d2, out, 5);
    for (i=0;i<5;i++) {
      printf("CSPL_Array_multiply[%ld]=%lf  %lf\n", i, out[i], answer[i]);
      assert_float_test(out[i], answer[i], 1e-5);
    }
  }
  {
    double d1[5] = {2,   3.4, 5.6, 4.5, 3.1};
    double d2[5] = {4.5, 2.3, 3.4, 1.0, 4.5};
    double answer[5] = {0.444444, 1.478261, 1.647059, 4.5, 0.688889};
    double out[5];
    long i;
    CSPL_Array_divide(d1, d2, out, 5);
    for (i=0;i<5;i++) {
      printf("CSPL_Array_divide[%ld]=%lf  %lf\n", i, out[i], answer[i]);
      assert_float_test(out[i], answer[i], 1e-5);
    }
  }
  {
    double d1[5] = {2,   3.4, 5.6, 4.5, 3.1};
    double answer = 2.0;
    double out;	     
    out = CSPL_Array_min(d1, 5);
    assert_float_test(out, answer, 1e-5);
  }
  {
    double d1[5] = {2,   3.4, 5.6, 4.5, 3.1};
    double answer = 5.6;
    double out;	     
    out = CSPL_Array_max(d1, 5);
    assert_float_test(out, answer, 1e-5);
  }
  {
    double d1[5] = {2,   3.4, 5.6, 4.5, 3.1};
    double answer = 3.6;
    double out;	     
    out = CSPL_Array_range(d1, 5);
    printf("CSPL_Array_range: %lf, %lf\n", out, answer);
    assert_float_test(out, answer, 1e-5);
  }
  {
    double d1[5] = {2,   3.4, 5.6, 4.5, 3.1};
    double answer1[5] = {2,3.4,5.6, 4.5, 3.1};
    double answer2[5] = {3,3.4,5.6, 4.5, 3.1};
    double answer3[5] = {3,3.4,5.5, 4.5, 3.1};
    double answer4[5] = {-4, -4, -4, -4, -4};
    long i;
    CSPL_Array_clip(d1, 0, 10, 5);
    for (i=0;i<5;i++) {
      printf("CSPL_Array_clip[%ld]=%lf  %lf\n", i, d1[i], answer1[i]);
      assert_float_test(d1[i], answer1[i], 1e-5);
    }
    CSPL_Array_clip(d1, 3, 10, 5);
    for (i=0;i<5;i++) {
      printf("CSPL_Array_clip[%ld]=%lf  %lf\n", i, d1[i], answer2[i]);
      assert_float_test(d1[i], answer2[i], 1e-5);
    }
    CSPL_Array_clip(d1, 3, 5.5, 5);
    for (i=0;i<5;i++) {
      printf("CSPL_Array_clip[%ld]=%lf  %lf\n", i, d1[i], answer3[i]);
      assert_float_test(d1[i], answer3[i], 1e-5);
    }
    CSPL_Array_clip(d1, -10, -4, 5);
    for (i=0;i<5;i++) {
      printf("CSPL_Array_clip[%ld]=%lf  %lf\n", i, d1[i], answer4[i]);
      assert_float_test(d1[i], answer4[i], 1e-5);
    }  
  }
  
  {
    double d1[5] = {5.6,   3.4, 2, 4.5, 3.1};
    double answer1[5] = {2, 3.1, 3.4, 4.5, 5.6};
    unsigned long i;
    double tst;
    for (i=0;i<5;i++) {
      tst = CSPL_Array_quickselect(i, d1, 0, 4);
      printf("CSPL_Array_quickselect(%ld, d1, 0, 4)=%lf\n", i, tst);
      assert_float_test(tst, answer1[i], 1e-5);
    }
  }

  {
    double d1[5] = {5.6,   3.4, 2, 4.5, 3.1};
    double answer1[5] = {2, 3.4, 4.5, 5.6};
    unsigned long i;
    double tst;
    for (i=0;i<4;i++) {
      tst = CSPL_Array_quickselect(i, d1, 0, 3);
      printf("CSPL_Array_quickselect(%ld, d1, 0, 3)=%lf\n", i, tst);
      assert_float_test(tst, answer1[i], 1e-5);
    }
  }

  {
    double dat1[5] = {1, 2, 5, 7, 8};
    long ans, i;
    double val;
    
    for (i=0; i<5; i++)
      printf("dat1[%ld]=%lf\n", i, dat1[i]);

    val = -1;
    ans = CSPL_Array_bisect(val, dat1, 5);
    printf("CSPL_Array_bisect(%lf, dat1, 5)=%ld\n", val, ans);
    assert_long_test(0, ans);

    val = 1.5;
    ans = CSPL_Array_bisect(val, dat1, 5);
    printf("CSPL_Array_bisect(%lf, dat1, 5)=%ld\n", val, ans);
    assert_long_test(1, ans);
    
    val = 5.0;
    ans = CSPL_Array_bisect(val, dat1, 5);
    printf("CSPL_Array_bisect(%lf, dat1, 5)=%ld\n", val, ans);
    assert_long_test(3, ans);

    val = 5.5;
    ans = CSPL_Array_bisect(val, dat1, 5);
    printf("CSPL_Array_bisect(%lf, dat1, 5)=%ld\n", val, ans);
    assert_long_test(3, ans);

    val = 8.5;
    ans = CSPL_Array_bisect(val, dat1, 5);
    printf("CSPL_Array_bisect(%lf, dat1, 5)=%ld\n", val, ans);
    assert_long_test(5, ans);
  }

  {
    // this was added after BAL found a bug
    double dat1[5] = {1, 4, 7, 8, 9};
    long ans, i;
    double val;
    
    for (i=0; i<5; i++)
      printf("dat1[%ld]=%lf\n", i, dat1[i]);

    val = 0;
    ans = CSPL_Array_bisect(val, dat1, 5);
    printf("CSPL_Array_bisect(%lf, dat1, 5)=%ld\n", val, ans);
    assert_long_test(0, ans);

    val = 3;
    ans = CSPL_Array_bisect(val, dat1, 5);
    printf("CSPL_Array_bisect(%lf, dat1, 5)=%ld\n", val, ans);
    assert_long_test(1, ans);
    
    val = 4.0;
    ans = CSPL_Array_bisect(val, dat1, 5);
    printf("CSPL_Array_bisect(%lf, dat1, 5)=%ld\n", val, ans);
    assert_long_test(2, ans);
  }

  {
    // test CSPL_Array_linspace()
    double ans[10] = {12.3       ,  14.73333333,  17.16666667,  19.6       ,
		      22.03333333,  24.46666667,  26.9       ,  29.33333333,
		      31.76666667,  34.2  };
    long i;
    double outval[10];

    CSPL_Array_linspace(outval, 12.3, 34.2, 10);
    for (i=0;i<10;i++) {
      printf("CSPL_Array_linspace[%ld]=%lf  ->  %lf\n", i, outval[i], ans[i]);
      assert_float_test(outval[i], ans[i], 1e-5);	  
    }
  }

  {
    // test CSPL_Array_logspace()
    double ans[10] = {12.3       ,  13.78008475,  15.4382712 ,  17.2959907 ,
		      19.37725347,  21.70895895,  24.32124343,  27.24786957,
		      30.52666276,  34.2  };
    long i;
    double outval[10];

    CSPL_Array_logspace(outval, 12.3, 34.2, 10);
    for (i=0;i<10;i++) {
      printf("CSPL_Array_logspace[%ld]=%lf  ->  %lf\n", i, outval[i], ans[i]);
      assert_float_test(outval[i], ans[i], 1e-5);	  
    }
  }

  return(0);
}

