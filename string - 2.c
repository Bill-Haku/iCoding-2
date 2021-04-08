#include<stdio.h>
#include<stdlib.h>

int get_len(const char* s) {
    int i = 0;
    while (s[i]) {
        i++;
    }
    return i;
}

int str_replace(const char* in, char* out, int outlen, const char* oldstr, const char* newstr) {
    int count_times = 0;
    int i;
    int j = 0;
    int k;
    int flag = 0;
    for (i = 0; outlen > 1 && in[i] != 0; i++) {
        if (in[i] != oldstr[0]) {
            out[j] = in[i];
            j++;
            outlen--;
            continue;
        } else {
            flag = 0;
            for (k = 0; oldstr[k] != 0; k++) {
                if (in[k + i] != oldstr[k]) {
                    break;
                } else {
                    if (k == (get_len(oldstr) - 1)) {
                        if (outlen > get_len(newstr)) {
                            i += k;
                            flag = 1;
                        }
                    }
                }
            }
            if (flag == 1) {
                count_times++;
                for (k = 0; newstr[k] != 0; k++) {
                    out[j] = newstr[k];
                    j++;
                    outlen--;
                }
            } else {
                out[j] = in[i];
                j++;
                outlen--;
            }
        }
    }
    out[j] = 0;
    return count_times;
}

int main() {
	return 0;
}