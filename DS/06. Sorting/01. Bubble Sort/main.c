#include <stdio.h>
#include <string.h>

void BubbleSort(int arr[], int n)
{

  for (int i = 0; i < n - 1; i++)
  {

    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main()
{

  int arr[] = {947, 521, 304, 114, 319, 790, 27, 417, 185, 522, 253, 67, 210, 640, 793, 19, 464, 238, 104, 498, 907, 235, 910, 598, 191, 169, 368, 270, 698, 623, 753, 551, 72, 425, 255, 580, 520, 754, 214, 404, 991, 141, 887, 826, 140, 547, 373, 485, 446, 36, 644, 763, 990, 930, 8, 510, 763, 860, 423, 684, 610, 400, 217, 877, 602, 882, 498, 935, 383, 181, 343, 604, 721, 675, 947, 961, 675, 607, 693, 44, 233, 300, 511, 358, 545, 255, 110, 912, 225, 175, 521, 930, 215, 15, 806, 483, 266, 605, 553, 790, 122, 249, 628, 966, 878, 735, 851, 107, 388, 697, 466, 661, 991, 871, 422, 278, 142, 534, 530, 577, 770, 320, 4, 394, 160, 905, 477, 492, 720, 383, 404, 304, 150, 214, 805, 260, 528, 846, 366, 919, 642, 970, 125, 853, 82, 487, 39, 286, 687, 503, 48, 139, 732, 575, 622, 999, 678, 492, 786, 469, 323, 919, 26, 844, 707, 252, 825, 752, 461, 461, 60, 891, 557, 875, 52, 190, 607, 247, 467, 451, 784, 48, 883, 119, 901, 303, 981, 183, 120, 907, 577, 519, 54, 736, 361, 608, 662, 287, 849, 139, 714, 763, 506, 260, 37, 124, 575, 288, 212, 551, 61, 689, 277, 705, 697, 48, 742, 674, 816, 206, 747, 746, 453, 274, 885, 767, 328, 235, 299, 245, 735, 394, 275, 897, 117, 115, 302, 701, 144, 23, 69, 589, 451, 282, 614, 327, 481, 176, 690, 939, 480, 655, 183, 984, 585, 980, 109, 410, 647, 939, 913, 553, 180, 304, 943, 833, 975, 918, 535, 83, 146, 8, 337, 936, 188, 305, 989, 4, 818, 136, 208, 500, 859, 125, 420, 364, 345, 251, 470, 136, 861, 912, 729, 661, 456, 968, 99, 790, 256, 106, 370, 648, 227, 151, 904, 819, 122, 898, 653, 683, 65, 574, 44, 282, 633, 748, 162, 608, 361, 260, 30, 604, 422, 727, 53, 320, 114, 642, 188, 260, 782, 908, 408, 965, 491, 581, 62, 395, 768, 8, 401, 974, 813, 556, 127, 562, 769, 992, 786, 576, 995, 105, 59, 101, 18, 610, 96, 351, 322, 618, 232, 949, 40, 87, 891, 64, 441, 743, 428, 439, 934, 454, 952, 508, 174, 602, 460, 913, 350, 993, 657, 835, 189, 214, 821, 541, 531, 606, 339, 541, 208, 804, 478, 350, 287, 321, 479, 992, 168, 473, 649, 808, 72, 870, 353, 248, 431, 483, 350, 870, 511, 538, 247, 465, 764, 837, 846, 473, 307, 89, 47, 182, 687, 229, 42, 776, 452, 439, 892, 260, 347, 26, 483, 600, 511, 637, 431, 741, 618, 110, 998, 511, 477, 941, 540, 700, 799, 367, 14, 340, 214, 3, 210, 589, 274, 770, 114, 582, 911, 819, 457, 827, 561, 396, 714, 735, 531, 376, 577, 756, 433, 567, 824, 67, 39, 200, 241, 987, 179, 760, 457, 741, 199, 791, 822, 207, 421, 554, 386, 169, 924, 288, 352, 609, 353, 950, 136, 711, 236, 121};
  int n = 500;
  BubbleSort(arr, n);
  for (int i = 0; i < n; i++)
  {
    printf("%d\n", arr[i]);
  }
}