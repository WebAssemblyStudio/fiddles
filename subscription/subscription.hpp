/**
 *  @file
 *  @copyright defined in bon/LICENSE.txt
 */
#pragma once

#include <bonlib/asset.hpp>
#include <bonlib/bon.hpp>
#include <bonlib/contract.hpp>
#include <string>

using bon::contract;
using bon::indexed_by;
using bon::const_mem_fun;

class subscription : public contract {


  public:
    subscription(account_name self) : contract(self), order_table(_self, _self) {}

    void subscribe(account_name buyer, uint64_t crate_id, uint32_t crate_num);
    void updatestate(uint64_t id, uint8_t state);
    void unsubscribe(uint64_t id);

  private:

    // @abi table order i64
    struct order {
      uint64_t id;          // 订单号
      account_name buyer;   // 购买者
      uint64_t crate_id;    // 商品id
      uint32_t crate_num;   // 商品个数
      uint32_t createdT;    // 创建时间
      uint32_t updatedT;    // 更新时间
      uint8_t state;        // 订单状态

      uint64_t primary_key() const { return id; }
      uint64_t by_buyer() const { return buyer; }

      BONLIB_SERIALIZE(order, (id)(buyer)(crate_id)(crate_num)(createdT)(updatedT)(state))
    };

    void ords_append(order &ord);
    void ords_update(order &ord);
    void ords_remove(uint64_t id);

    typedef bon::multi_index<N(order), order,
    indexed_by<N(buyer), const_mem_fun<order, account_name, &order::by_buyer>>>
      Orders_index;
    Orders_index order_table;

  public:
  
    enum ORDER_STATE {
      ORDER_STATE_SUBSCRIBED, // 订购
      ORDER_STATE_DELIVERING, // 配送
      ORDER_STATE_COMPLETED,  // 完成
    };
};

BON_ABI(subscription, (subscribe)(updatestate)(unsubscribe))
