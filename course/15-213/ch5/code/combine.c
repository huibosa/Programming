typedef double data_t;

#define IDENT 1
#define OP *

typedef struct {
  long len;
  data_t *data;
} vec_rec, *vec_ptr;

long vec_length(vec_ptr v) { return v->len; }

data_t *get_vec_start(vec_ptr v) { return v->data; }

void get_vec_element(vec_ptr v, long i, data_t *val) { *val = v->data[i]; }

void combine1(vec_ptr v, data_t *dst) {
  long i;
  *dst = IDENT;
  for (i = 0; i < vec_length(v); i++) {
    data_t val;
    get_vec_element(v, i, &val);
    *dst = *dst OP val;
  }
}

void combine2(vec_ptr v, data_t *dst) {
  long i;
  long length = vec_length(v);

  *dst = IDENT;
  for (i = 0; i < length; i++) {
    data_t val;
    get_vec_element(v, i, &val);
    *dst = *dst OP val;
  }
}

void combine3(vec_ptr v, data_t *dst) {
  long i;
  long length = vec_length(v);
  data_t *data = get_vec_start(v);

  *dst = IDENT;
  for (i = 0; i < length; i++) {
    *dst = *dst OP data[i];
  }
}

void combine4(vec_ptr v, data_t *dst) {
  long i;
  long length = vec_length(v);
  data_t *data = get_vec_start(v);
  data_t acc = IDENT;

  for (i = 0; i < length; i++) {
    acc = acc OP data[i];
  }
  *dst = acc;
}

void combine5(vec_ptr v, data_t *dst) {
  long i;
  long length = vec_length(v);
  long limit = length - 1;
  data_t *data = get_vec_start(v);
  data_t acc = IDENT;

  for (i = 0; i < limit; i += 2) {
    acc = acc OP data[i + 1] OP data[i];
  }

  for (; i < length; i++) {
    acc = acc OP data[i];
  }

  *dst = acc;
}

void combine5p(vec_ptr v, data_t *dst) {
  long i;
  long length = vec_length(v);
  long limit = length - 5 + 1;
  data_t *data = get_vec_start(v);
  data_t acc = IDENT;

  for (i = 0; i < limit; i += 5) {
    acc = (data[i] OP acc)OP data[i + 1];
    acc = (data[i + 2] OP acc) OP data[i + 3];
    acc = acc OP data[i + 4];
  }
  for (; i < length; i++) {
    acc OP data[i];
  }

  *dst = acc;
}

void combine6(vec_ptr v, data_t *dst) {
  long i;
  long length = vec_length(v);
  long limit = length - 1;
  data_t *data = get_vec_start(v);
  data_t acc0 = IDENT;
  data_t acc1 = IDENT;

  for (i = 0; i < limit; i += 2) {
    acc0 = acc0 OP data[i];
    acc1 = acc1 OP data[i + 1];
  }

  for (; i < length; i++) {
    acc0 = acc0 OP data[i];
  }

  *dst = acc0 OP acc1;
}

void combine7(vec_ptr v, data_t *dst) {
  long i;
  long length = vec_length(v);
  long limit = length - 1;
  data_t *data = get_vec_start(v);
  data_t acc = IDENT;

  for (i = 0; i < limit; i += 2) {
    acc = acc OP (data[i] OP data[i+1]);
  }

  for (; i < length; i++) {
    acc = acc OP data[i];
  }

  *dst = acc;
}
