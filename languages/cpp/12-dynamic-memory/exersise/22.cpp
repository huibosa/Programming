#include "22.h"

ConstStrBlobPtr StrBlob::begin() const {
    ConstStrBlobPtr ret(*this);
    return ret;
}

ConstStrBlobPtr StrBlob::end() const {
    ConstStrBlobPtr ret(*this, data->size());
    return ret;
}
