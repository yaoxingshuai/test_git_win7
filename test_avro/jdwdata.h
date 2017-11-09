/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// ../avro-cpp-1.8.2_all_files/build/avrogencpp -i ./kafka_source_schema.json -o jdwdata.h

#ifndef JDWDATA_H_494351825__H_
#define JDWDATA_H_494351825__H_


#include <sstream>
#include "boost/any.hpp"
#include "Specific.hh"
#include "Encoder.hh"
#include "Decoder.hh"

struct _kafka_source_schema_json_Union__0__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    std::string get_string() const;
    void set_string(const std::string& v);
    bool is_null() const {
        return (idx_ == 1);
    }
    void set_null() {
        idx_ = 1;
        value_ = boost::any();
    }
    _kafka_source_schema_json_Union__0__();
};

struct _kafka_source_schema_json_Union__1__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    std::string get_string() const;
    void set_string(const std::string& v);
    bool is_null() const {
        return (idx_ == 1);
    }
    void set_null() {
        idx_ = 1;
        value_ = boost::any();
    }
    _kafka_source_schema_json_Union__1__();
};

struct _kafka_source_schema_json_Union__2__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    std::string get_string() const;
    void set_string(const std::string& v);
    bool is_null() const {
        return (idx_ == 1);
    }
    void set_null() {
        idx_ = 1;
        value_ = boost::any();
    }
    _kafka_source_schema_json_Union__2__();
};

struct _kafka_source_schema_json_Union__3__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    std::map<std::string, _kafka_source_schema_json_Union__2__ > get_map() const;
    void set_map(const std::map<std::string, _kafka_source_schema_json_Union__2__ >& v);
    bool is_null() const {
        return (idx_ == 1);
    }
    void set_null() {
        idx_ = 1;
        value_ = boost::any();
    }
    _kafka_source_schema_json_Union__3__();
};

struct JdwData {
    typedef _kafka_source_schema_json_Union__0__ ddl_t;
    typedef _kafka_source_schema_json_Union__1__ err_t;
    typedef _kafka_source_schema_json_Union__3__ src_t;
    int64_t mid;
    std::string db;
    int64_t ts;
    ddl_t ddl;
    err_t err;
    src_t src;
    JdwData() :
        mid(int64_t()),
        db(std::string()),
        ts(int64_t()),
        ddl(ddl_t()),
        err(err_t()),
        src(src_t())
        { }
};

inline
std::string _kafka_source_schema_json_Union__0__::get_string() const {
    if (idx_ != 0) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<std::string >(value_);
}

inline
void _kafka_source_schema_json_Union__0__::set_string(const std::string& v) {
    idx_ = 0;
    value_ = v;
}

inline
std::string _kafka_source_schema_json_Union__1__::get_string() const {
    if (idx_ != 0) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<std::string >(value_);
}

inline
void _kafka_source_schema_json_Union__1__::set_string(const std::string& v) {
    idx_ = 0;
    value_ = v;
}

inline
std::string _kafka_source_schema_json_Union__2__::get_string() const {
    if (idx_ != 0) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<std::string >(value_);
}

inline
void _kafka_source_schema_json_Union__2__::set_string(const std::string& v) {
    idx_ = 0;
    value_ = v;
}

inline
std::map<std::string, _kafka_source_schema_json_Union__2__ > _kafka_source_schema_json_Union__3__::get_map() const {
    if (idx_ != 0) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<std::map<std::string, _kafka_source_schema_json_Union__2__ > >(value_);
}

inline
void _kafka_source_schema_json_Union__3__::set_map(const std::map<std::string, _kafka_source_schema_json_Union__2__ >& v) {
    idx_ = 0;
    value_ = v;
}

inline _kafka_source_schema_json_Union__0__::_kafka_source_schema_json_Union__0__() : idx_(0), value_(std::string()) { }
inline _kafka_source_schema_json_Union__1__::_kafka_source_schema_json_Union__1__() : idx_(0), value_(std::string()) { }
inline _kafka_source_schema_json_Union__2__::_kafka_source_schema_json_Union__2__() : idx_(0), value_(std::string()) { }
inline _kafka_source_schema_json_Union__3__::_kafka_source_schema_json_Union__3__() : idx_(0), value_(std::map<std::string, _kafka_source_schema_json_Union__2__ >()) { }
namespace avro {
template<> struct codec_traits<_kafka_source_schema_json_Union__0__> {
    static void encode(Encoder& e, _kafka_source_schema_json_Union__0__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            avro::encode(e, v.get_string());
            break;
        case 1:
            e.encodeNull();
            break;
        }
    }
    static void decode(Decoder& d, _kafka_source_schema_json_Union__0__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            {
                std::string vv;
                avro::decode(d, vv);
                v.set_string(vv);
            }
            break;
        case 1:
            d.decodeNull();
            v.set_null();
            break;
        }
    }
};

template<> struct codec_traits<_kafka_source_schema_json_Union__1__> {
    static void encode(Encoder& e, _kafka_source_schema_json_Union__1__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            avro::encode(e, v.get_string());
            break;
        case 1:
            e.encodeNull();
            break;
        }
    }
    static void decode(Decoder& d, _kafka_source_schema_json_Union__1__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            {
                std::string vv;
                avro::decode(d, vv);
                v.set_string(vv);
            }
            break;
        case 1:
            d.decodeNull();
            v.set_null();
            break;
        }
    }
};

template<> struct codec_traits<_kafka_source_schema_json_Union__2__> {
    static void encode(Encoder& e, _kafka_source_schema_json_Union__2__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            avro::encode(e, v.get_string());
            break;
        case 1:
            e.encodeNull();
            break;
        }
    }
    static void decode(Decoder& d, _kafka_source_schema_json_Union__2__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            {
                std::string vv;
                avro::decode(d, vv);
                v.set_string(vv);
            }
            break;
        case 1:
            d.decodeNull();
            v.set_null();
            break;
        }
    }
};

template<> struct codec_traits<_kafka_source_schema_json_Union__3__> {
    static void encode(Encoder& e, _kafka_source_schema_json_Union__3__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            avro::encode(e, v.get_map());
            break;
        case 1:
            e.encodeNull();
            break;
        }
    }
    static void decode(Decoder& d, _kafka_source_schema_json_Union__3__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            {
                std::map<std::string, _kafka_source_schema_json_Union__2__ > vv;
                avro::decode(d, vv);
                v.set_map(vv);
            }
            break;
        case 1:
            d.decodeNull();
            v.set_null();
            break;
        }
    }
};

template<> struct codec_traits<JdwData> {
    static void encode(Encoder& e, const JdwData& v) {
        avro::encode(e, v.mid);
        avro::encode(e, v.db);
        avro::encode(e, v.ts);
        avro::encode(e, v.ddl);
        avro::encode(e, v.err);
        avro::encode(e, v.src);
    }
    static void decode(Decoder& d, JdwData& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.mid);
                    break;
                case 1:
                    avro::decode(d, v.db);
                    break;
                case 2:
                    avro::decode(d, v.ts);
                    break;
                case 3:
                    avro::decode(d, v.ddl);
                    break;
                case 4:
                    avro::decode(d, v.err);
                    break;
                case 5:
                    avro::decode(d, v.src);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.mid);
            avro::decode(d, v.db);
            avro::decode(d, v.ts);
            avro::decode(d, v.ddl);
            avro::decode(d, v.err);
            avro::decode(d, v.src);
        }
    }
};

}
#endif
