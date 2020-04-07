/* Copyright (c) 2020 vesoft inc. All rights reserved.
 *
 * obj source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#ifndef DATATYPES_VALUEOPS_H_
#define DATATYPES_VALUEOPS_H_

#include "base/Base.h"

#include <thrift/lib/cpp2/GeneratedSerializationCodeHelper.h>
#include <thrift/lib/cpp2/gen/module_types_tcc.h>
#include <thrift/lib/cpp2/protocol/ProtocolReaderStructReadState.h>

#include "datatypes/Value.h"
#include "datatypes/DateOps.h"
#include "datatypes/PathOps.h"
#include "datatypes/VertexOps.h"
#include "datatypes/EdgeOps.h"
#include "datatypes/ListOps.h"
#include "datatypes/MapOps.h"
#include "datatypes/SetOps.h"

namespace apache {
namespace thrift {

namespace detail {

template<>
struct TccStructTraits<nebula::Value> {
    static void translateFieldName(
            FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
            FOLLY_MAYBE_UNUSED int16_t& fid,
            FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
        if (_fname == "nVal") {
            fid = 1;
            _ftype = apache::thrift::protocol::T_I32;
        } else if (_fname == "bVal") {
            fid = 2;
            _ftype = apache::thrift::protocol::T_BOOL;
        } else if (_fname == "iVal") {
            fid = 3;
            _ftype = apache::thrift::protocol::T_I64;
        } else if (_fname == "fVal") {
            fid = 4;
            _ftype = apache::thrift::protocol::T_DOUBLE;
        } else if (_fname == "sVal") {
            fid = 5;
            _ftype = apache::thrift::protocol::T_STRING;
        } else if (_fname == "dVal") {
            fid = 6;
            _ftype = apache::thrift::protocol::T_STRUCT;
        } else if (_fname == "tVal") {
            fid = 7;
            _ftype = apache::thrift::protocol::T_STRUCT;
        } else if (_fname == "vVal") {
             fid = 8;
            _ftype = apache::thrift::protocol::T_STRUCT;
        } else if (_fname == "eVal") {
            fid = 9;
            _ftype = apache::thrift::protocol::T_STRUCT;
        } else if (_fname == "pVal") {
            fid = 10;
            _ftype = apache::thrift::protocol::T_STRUCT;
        } else if (_fname == "lVal") {
            fid = 11;
            _ftype = apache::thrift::protocol::T_STRUCT;
        } else if (_fname == "mVal") {
            fid = 12;
            _ftype = apache::thrift::protocol::T_STRUCT;
        } else if (_fname == "uVal") {
            fid = 13;
            _ftype = apache::thrift::protocol::T_STRUCT;
        }
    }
};

}  // namespace detail


template<>
inline void Cpp2Ops<nebula::Value>::clear(nebula::Value* obj) {
    return obj->clear();
}


template<>
inline constexpr apache::thrift::protocol::TType Cpp2Ops<nebula::Value>::thriftType() {
    return apache::thrift::protocol::T_STRUCT;
}


template<>
template<class Protocol>
uint32_t Cpp2Ops<nebula::Value>::write(Protocol* proto, nebula::Value const* obj) {
    uint32_t xfer = 0;
    xfer += proto->writeStructBegin("Value");

    switch (obj->type()) {
        case nebula::Value::Type::NULLVALUE:
        {
            xfer += proto->writeFieldBegin("nVal", apache::thrift::protocol::T_I32, 1);
            xfer += detail::pm::protocol_methods<type_class::enumeration, nebula::NullType>
                ::write(*proto, obj->getNull());
            xfer += proto->writeFieldEnd();
            break;
        }
        case nebula::Value::Type::BOOL:
        {
            xfer += proto->writeFieldBegin("bVal", apache::thrift::protocol::T_BOOL, 2);
            xfer += proto->writeBool(obj->getBool());
            xfer += proto->writeFieldEnd();
            break;
        }
        case nebula::Value::Type::INT:
        {
            xfer += proto->writeFieldBegin("iVal", apache::thrift::protocol::T_I64, 3);
            xfer += detail::pm::protocol_methods<type_class::integral, int64_t>
                ::write(*proto, obj->getInt());
            xfer += proto->writeFieldEnd();
            break;
        }
        case nebula::Value::Type::FLOAT:
        {
            xfer += proto->writeFieldBegin("fVal", apache::thrift::protocol::T_DOUBLE, 4);
            xfer += proto->writeDouble(obj->getFloat());
            xfer += proto->writeFieldEnd();
            break;
        }
        case nebula::Value::Type::STRING:
        {
            xfer += proto->writeFieldBegin("sVal", apache::thrift::protocol::T_STRING, 5);
            xfer += proto->writeBinary(obj->getStr());
            xfer += proto->writeFieldEnd();
            break;
        }
        case nebula::Value::Type::DATE:
        {
            xfer += proto->writeFieldBegin("dVal", apache::thrift::protocol::T_STRUCT, 6);
            xfer += Cpp2Ops<nebula::Date>::write(proto, &obj->getDate());
            xfer += proto->writeFieldEnd();
            break;
        }
        case nebula::Value::Type::DATETIME:
        {
            xfer += proto->writeFieldBegin("tVal", apache::thrift::protocol::T_STRUCT, 7);
            xfer += Cpp2Ops<nebula::DateTime>::write(proto, &obj->getDateTime());
            xfer += proto->writeFieldEnd();
            break;
        }
        case nebula::Value::Type::VERTEX:
        {
            xfer += proto->writeFieldBegin("vVal", apache::thrift::protocol::T_STRUCT, 8);
            if (obj->getVertexPtr()) {
                xfer += Cpp2Ops<nebula::Vertex>::write(proto, obj->getVertexPtr());
            } else {
                xfer += proto->writeStructBegin("Vertex");
                xfer += proto->writeStructEnd();
                xfer += proto->writeFieldStop();
            }
            xfer += proto->writeFieldEnd();
            break;
        }
        case nebula::Value::Type::EDGE:
        {
            xfer += proto->writeFieldBegin("eVal", apache::thrift::protocol::T_STRUCT, 9);
            if (obj->getEdgePtr()) {
                xfer += Cpp2Ops<nebula::Edge>::write(proto, obj->getEdgePtr());
            } else {
                xfer += proto->writeStructBegin("Edge");
                xfer += proto->writeStructEnd();
                xfer += proto->writeFieldStop();
            }
            xfer += proto->writeFieldEnd();
            break;
        }
        case nebula::Value::Type::PATH:
        {
            xfer += proto->writeFieldBegin("pVal", apache::thrift::protocol::T_STRUCT, 10);
            if (obj->getPathPtr()) {
                xfer += Cpp2Ops<nebula::Path>::write(proto, obj->getPathPtr());
            } else {
                xfer += proto->writeStructBegin("Path");
                xfer += proto->writeStructEnd();
                xfer += proto->writeFieldStop();
            }
            xfer += proto->writeFieldEnd();
            break;
        }
        case nebula::Value::Type::LIST:
        {
            xfer += proto->writeFieldBegin("lVal", apache::thrift::protocol::T_STRUCT, 11);
            if (obj->getListPtr()) {
                xfer += Cpp2Ops<nebula::List>::write(proto, obj->getListPtr());
            } else {
                xfer += proto->writeStructBegin("List");
                xfer += proto->writeStructEnd();
                xfer += proto->writeFieldStop();
            }
            xfer += proto->writeFieldEnd();
            break;
        }
        case nebula::Value::Type::MAP:
        {
            xfer += proto->writeFieldBegin("mVal", apache::thrift::protocol::T_STRUCT, 12);
            if (obj->getMapPtr()) {
                xfer += Cpp2Ops<nebula::Map>::write(proto, obj->getMapPtr());
            } else {
                xfer += proto->writeStructBegin("Map");
                xfer += proto->writeStructEnd();
                xfer += proto->writeFieldStop();
            }
            xfer += proto->writeFieldEnd();
            break;
        }
        case nebula::Value::Type::SET:
        {
            xfer += proto->writeFieldBegin("uVal", apache::thrift::protocol::T_STRUCT, 13);
            if (obj->getSetPtr()) {
                xfer += Cpp2Ops<nebula::Set>::write(proto, obj->getSetPtr());
            } else {
                xfer += proto->writeStructBegin("Set");
                xfer += proto->writeStructEnd();
                xfer += proto->writeFieldStop();
            }
            xfer += proto->writeFieldEnd();
            break;
        }
        case nebula::Value::Type::__EMPTY__:
        {
            break;
        }
    }

    xfer += proto->writeFieldStop();
    xfer += proto->writeStructEnd();
    return xfer;
}


template<>
template<class Protocol>
void Cpp2Ops<nebula::Value>::read(Protocol* proto, nebula::Value* obj) {
    detail::ProtocolReaderStructReadState<Protocol> readState;
    readState.fieldId = 0;

    readState.readStructBegin(proto);

    using apache::thrift::TProtocolException;

    readState.readFieldBegin(proto);
    if (readState.fieldType == apache::thrift::protocol::T_STOP) {
        obj->clear();
    } else {
        if (proto->kUsesFieldNames()) {
            detail::TccStructTraits<nebula::Value>::translateFieldName(readState.fieldName(),
                                                                       readState.fieldId,
                                                                       readState.fieldType);
        }
        switch (readState.fieldId) {
            case 1:
            {
                if (readState.fieldType == apache::thrift::protocol::T_I32) {
                    obj->setNull(nebula::NullType::__NULL__);
                    detail::pm::protocol_methods<type_class::enumeration, nebula::NullType>
                        ::read(*proto, obj->mutableNull());
                } else {
                    proto->skip(readState.fieldType);
                }
                break;
            }
            case 2:
            {
                if (readState.fieldType == apache::thrift::protocol::T_BOOL) {
                    obj->setBool(false);
                    proto->readBool(obj->mutableBool());
                } else {
                    proto->skip(readState.fieldType);
                }
                break;
            }
            case 3:
            {
                if (readState.fieldType == apache::thrift::protocol::T_I64) {
                    obj->setInt(0);
                    detail::pm::protocol_methods<type_class::integral, int64_t>
                        ::read(*proto, obj->mutableInt());
                } else {
                    proto->skip(readState.fieldType);
                }
                break;
            }
            case 4:
            {
                if (readState.fieldType == apache::thrift::protocol::T_DOUBLE) {
                    obj->setFloat(0.0);
                    proto->readDouble(obj->mutableFloat());
                } else {
                    proto->skip(readState.fieldType);
                }
                break;
            }
            case 5:
            {
                if (readState.fieldType == apache::thrift::protocol::T_STRING) {
                    obj->setStr("");
                    proto->readBinary(obj->mutableStr());
                } else {
                    proto->skip(readState.fieldType);
                }
                break;
            }
            case 6:
            {
                if (readState.fieldType == apache::thrift::protocol::T_STRUCT) {
                    obj->setDate(nebula::Date());
                    Cpp2Ops<nebula::Date>::read(proto, &obj->mutableDate());
                } else {
                    proto->skip(readState.fieldType);
                }
                break;
            }
            case 7:
            {
                if (readState.fieldType == apache::thrift::protocol::T_STRUCT) {
                    obj->setDateTime(nebula::DateTime());
                    Cpp2Ops<nebula::DateTime>::read(proto, &obj->mutableDateTime());
                } else {
                    proto->skip(readState.fieldType);
                }
                break;
            }
            case 8:
            {
                if (readState.fieldType == apache::thrift::protocol::T_STRUCT) {
                    obj->setVertex(nebula::Vertex());
                    Cpp2Ops<nebula::Vertex>::read(proto, &obj->mutableVertex());
                } else {
                    proto->skip(readState.fieldType);
                }
                break;
            }
            case 9:
            {
                if (readState.fieldType == apache::thrift::protocol::T_STRUCT) {
                    obj->setEdge(nebula::Edge());
                    Cpp2Ops<nebula::Edge>::read(proto, &obj->mutableEdge());
                } else {
                    proto->skip(readState.fieldType);
                }
                break;
            }
            case 10:
            {
                if (readState.fieldType == apache::thrift::protocol::T_STRUCT) {
                    obj->setPath(nebula::Path());
                    Cpp2Ops< nebula::Path>::read(proto, &obj->mutablePath());
                } else {
                    proto->skip(readState.fieldType);
                }
                break;
            }
            case 11:
            {
                if (readState.fieldType == apache::thrift::protocol::T_STRUCT) {
                    obj->setList(nebula::List());
                    Cpp2Ops<nebula::List>::read(proto, &obj->mutableList());
                } else {
                    proto->skip(readState.fieldType);
                }
                break;
            }
            case 12:
            {
                if (readState.fieldType == apache::thrift::protocol::T_STRUCT) {
                    obj->setMap(nebula::Map());
                    Cpp2Ops<nebula::Map>::read(proto, &obj->mutableMap());
                } else {
                    proto->skip(readState.fieldType);
                }
                break;
            }
            case 13:
            {
                if (readState.fieldType == apache::thrift::protocol::T_STRUCT) {
                    obj->setSet(nebula::Set());
                    Cpp2Ops<nebula::Set>::read(proto, &obj->mutableSet());
                } else {
                    proto->skip(readState.fieldType);
                }
                break;
            }
            default:
            {
                proto->skip(readState.fieldType);
                break;
            }
        }

        readState.readFieldEnd(proto);
        readState.readFieldBegin(proto);

        if (UNLIKELY(readState.fieldType != apache::thrift::protocol::T_STOP)) {
            using apache::thrift::protocol::TProtocolException;
            TProtocolException::throwUnionMissingStop();
        }
    }

    readState.readStructEnd(proto);
}


template<>
template<class Protocol>
uint32_t Cpp2Ops<nebula::Value>::serializedSize(Protocol const* proto,
                                                nebula::Value const* obj) {
    uint32_t xfer = 0;
    xfer += proto->serializedStructSize("Value");

    switch (obj->type()) {
        case nebula::Value::Type::NULLVALUE:
        {
            xfer += proto->serializedFieldSize("nVal", protocol::T_I32, 1);
            xfer += detail::pm::protocol_methods<type_class::enumeration, nebula::NullType>
                ::serializedSize<false>(*proto, obj->getNull());
            break;
        }
        case nebula::Value::Type::BOOL:
        {
            xfer += proto->serializedFieldSize("bVal", protocol::T_BOOL, 2);
            xfer += proto->serializedSizeBool(obj->getBool());
            break;
        }
        case nebula::Value::Type::INT:
        {
            xfer += proto->serializedFieldSize("iVal", protocol::T_I64, 3);
            xfer += detail::pm::protocol_methods<type_class::integral, int64_t>
                ::serializedSize<false>(*proto, obj->getInt());
            break;
        }
        case nebula::Value::Type::FLOAT:
        {
            xfer += proto->serializedFieldSize("fVal", protocol::T_DOUBLE, 4);
            xfer += proto->serializedSizeDouble(obj->getFloat());
            break;
        }
        case nebula::Value::Type::STRING:
        {
            xfer += proto->serializedFieldSize("sVal", protocol::T_STRING, 5);
            xfer += proto->serializedSizeBinary(obj->getStr());
            break;
        }
        case nebula::Value::Type::DATE:
        {
            xfer += proto->serializedFieldSize("dVal", protocol::T_STRUCT, 6);
            xfer += Cpp2Ops<nebula::Date>::serializedSize(proto, &obj->getDate());
            break;
        }
        case nebula::Value::Type::DATETIME:
        {
            xfer += proto->serializedFieldSize("tVal", protocol::T_STRUCT, 7);
            xfer += Cpp2Ops<nebula::DateTime>::serializedSize(proto, &obj->getDateTime());
            break;
        }
        case nebula::Value::Type::VERTEX:
        {
            xfer += proto->serializedFieldSize("vVal", protocol::T_STRUCT, 8);
            if (obj->getVertexPtr()) {
                xfer += Cpp2Ops<nebula::Vertex>
                    ::serializedSize(proto, obj->getVertexPtr());
            } else {
                xfer += proto->serializedStructSize("Vertex");
                xfer += proto->serializedSizeStop();
            }
            break;
        }
        case nebula::Value::Type::EDGE:
        {
            xfer += proto->serializedFieldSize("eVal", protocol::T_STRUCT, 9);
            if (obj->getEdgePtr()) {
                xfer += Cpp2Ops<nebula::Edge>::serializedSize(proto, obj->getEdgePtr());
            } else {
                xfer += proto->serializedStructSize("Edge");
                xfer += proto->serializedSizeStop();
            }
            break;
        }
        case nebula::Value::Type::PATH:
        {
            xfer += proto->serializedFieldSize("pVal", protocol::T_STRUCT, 10);
            if (obj->getPathPtr()) {
                xfer += Cpp2Ops<nebula::Path>::serializedSize(proto, obj->getPathPtr());
            } else {
                xfer += proto->serializedStructSize("Path");
                xfer += proto->serializedSizeStop();
            }
            break;
        }
        case nebula::Value::Type::LIST:
        {
            xfer += proto->serializedFieldSize("lVal", protocol::T_STRUCT, 11);
            if (obj->getListPtr()) {
                xfer += Cpp2Ops<nebula::List>::serializedSize(proto, obj->getListPtr());
            } else {
                xfer += proto->serializedStructSize("List");
                xfer += proto->serializedSizeStop();
            }
            break;
        }
        case nebula::Value::Type::MAP:
        {
            xfer += proto->serializedFieldSize("mVal", protocol::T_STRUCT, 12);
            if (obj->getMapPtr()) {
                xfer += Cpp2Ops<nebula::Map>::serializedSize(proto, obj->getMapPtr());
            } else {
                xfer += proto->serializedStructSize("Map");
                xfer += proto->serializedSizeStop();
            }
            break;
        }
        case nebula::Value::Type::SET:
        {
            xfer += proto->serializedFieldSize("uVal", protocol::T_STRUCT, 13);
            if (obj->getSetPtr()) {
                xfer += Cpp2Ops<nebula::Set>::serializedSize(proto, obj->getSetPtr());
            } else {
                xfer += proto->serializedStructSize("Set");
                xfer += proto->serializedSizeStop();
            }
            break;
        }
        case nebula::Value::Type::__EMPTY__:
        {
            break;
        }
    }

    xfer += proto->serializedSizeStop();
    return xfer;
}


template<>
template<class Protocol>
uint32_t Cpp2Ops<nebula::Value>::serializedSizeZC(Protocol const* proto,
                                                  nebula::Value const* obj) {
    uint32_t xfer = 0;
    xfer += proto->serializedStructSize("Value");

    switch (obj->type()) {
        case nebula::Value::Type::NULLVALUE:
        {
            xfer += proto->serializedFieldSize("nVal", protocol::T_I32, 1);
            xfer += detail::pm::protocol_methods<type_class::enumeration, nebula::NullType>
                ::serializedSize<false>(*proto, obj->getNull());
            break;
        }
        case nebula::Value::Type::BOOL:
        {
            xfer += proto->serializedFieldSize("bVal", protocol::T_BOOL, 2);
            xfer += proto->serializedSizeBool(obj->getBool());
            break;
        }
        case nebula::Value::Type::INT:
        {
            xfer += proto->serializedFieldSize("iVal", protocol::T_I64, 3);
            xfer += detail::pm::protocol_methods<type_class::integral, int64_t>
                ::serializedSize<false>(*proto, obj->getInt());
            break;
        }
        case nebula::Value::Type::FLOAT:
        {
            xfer += proto->serializedFieldSize("fVal", protocol::T_DOUBLE, 4);
            xfer += proto->serializedSizeDouble(obj->getFloat());
            break;
        }
        case nebula::Value::Type::STRING:
        {
            xfer += proto->serializedFieldSize("sVal", protocol::T_STRING, 5);
            xfer += proto->serializedSizeZCBinary(obj->getStr());
            break;
        }
        case nebula::Value::Type::DATE:
        {
            xfer += proto->serializedFieldSize("dVal", protocol::T_STRUCT, 6);
            xfer += Cpp2Ops<nebula::Date>::serializedSizeZC(proto, &obj->getDate());
            break;
        }
        case nebula::Value::Type::DATETIME:
        {
            xfer += proto->serializedFieldSize("tVal", protocol::T_STRUCT, 7);
            xfer += Cpp2Ops<nebula::DateTime>::serializedSizeZC(proto, &obj->getDateTime());
            break;
        }
        case nebula::Value::Type::VERTEX:
        {
            xfer += proto->serializedFieldSize("vVal", protocol::T_STRUCT, 8);
            if (obj->getVertexPtr()) {
                xfer += Cpp2Ops<nebula::Vertex>::serializedSizeZC(proto, obj->getVertexPtr());
            } else {
                xfer += proto->serializedStructSize("Vertex");
                xfer += proto->serializedSizeStop();
            }
            break;
        }
        case nebula::Value::Type::EDGE:
        {
            xfer += proto->serializedFieldSize("eVal", protocol::T_STRUCT, 9);
            if (obj->getEdgePtr()) {
                xfer += Cpp2Ops<nebula::Edge>::serializedSizeZC(proto, obj->getEdgePtr());
            } else {
                xfer += proto->serializedStructSize("Edge");
                xfer += proto->serializedSizeStop();
            }
            break;
        }
        case nebula::Value::Type::PATH:
        {
            xfer += proto->serializedFieldSize("pVal", protocol::T_STRUCT, 10);
            if (obj->getPathPtr()) {
                xfer += Cpp2Ops<nebula::Path>::serializedSizeZC(proto, obj->getPathPtr());
            } else {
                xfer += proto->serializedStructSize("Path");
                xfer += proto->serializedSizeStop();
            }
            break;
        }
        case nebula::Value::Type::LIST:
        {
            xfer += proto->serializedFieldSize("lVal", protocol::T_STRUCT, 11);
            if (obj->getListPtr()) {
                xfer += Cpp2Ops<nebula::List>::serializedSizeZC(proto, obj->getListPtr());
            } else {
                xfer += proto->serializedStructSize("List");
                xfer += proto->serializedSizeStop();
            }
            break;
        }
        case nebula::Value::Type::MAP:
        {
            xfer += proto->serializedFieldSize("mVal", protocol::T_STRUCT, 12);
            if (obj->getMapPtr()) {
                xfer += Cpp2Ops<nebula::Map>::serializedSizeZC(proto, obj->getMapPtr());
            } else {
                xfer += proto->serializedStructSize("Map");
                xfer += proto->serializedSizeStop();
            }
            break;
        }
        case nebula::Value::Type::SET:
        {
            xfer += proto->serializedFieldSize("uVal", protocol::T_STRUCT, 13);
            if (obj->getSetPtr()) {
                xfer += Cpp2Ops<nebula::Set>::serializedSizeZC(proto, obj->getSetPtr());
            } else {
                xfer += proto->serializedStructSize("Set");
                xfer += proto->serializedSizeStop();
            }
            break;
        }
        case nebula::Value::Type::__EMPTY__:
        {
            break;
        }
    }

    xfer += proto->serializedSizeStop();
    return xfer;
}

}  // namespace thrift
}  // namespace apache
#endif  // DATATYPES_VALUEOPS_H_
