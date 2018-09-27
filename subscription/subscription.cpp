/**
 *  @file
 *  @copyright defined in bon/LICENSE.txt
 */

#include "subscription.hpp"
dsadsa
void subscription::ords_append(order &ord)
{
    auto next_id = order_table.available_primary_key();
    order_table.emplace(_self, [&](auto &o) {
        o.id = next_id;
        o.buyer = ord.buyer;
        o.crate_id = ord.crate_id;
        o.crate_num = ord.crate_num;
        o.createdT = ord.createdT;
        o.updatedT = ord.updatedT;
        o.state = ord.state;
    });
}

void subscription::ords_update(order &ord)
{
    auto it = order_table.find(ord.id);
    bon_assert(it != order_table.end(), "id does not exist;");
    const auto &ordi = *it;

    order_table.modify(ordi, 0, [&](auto &o) {
        o.id = ord.id;
        o.buyer = ord.buyer;
        o.crate_id = ord.crate_id;
        o.crate_num = ord.crate_num;
        o.createdT = ord.createdT;
        o.updatedT = ord.updatedT;
        o.state = ord.state;
    });
}

void subscription::ords_remove(uint64_t id)
{
    auto it = order_table.find(id);
    const auto &ord = *it;
    bon_assert(it != order_table.end(), "id does not exist;");

    order_table.erase(it);
}

void subscription::subscribe(account_name buyer, uint64_t crate_id, uint32_t crate_num)
{
    require_auth(_self);

    bon_assert(is_account(buyer), "buyer does not exist;");

    auto now_t = now();
    order ord = {0, buyer, crate_id, crate_num, now_t, now_t, ORDER_STATE_SUBSCRIBED};

    this->ords_append(ord);
}

void subscription::updatestate(uint64_t id, uint8_t state)
{
    require_auth(_self);

    auto it = order_table.find(id);
    const auto &ord = *it;
    bon_assert(it != order_table.end(), "id does not exist;");
    bon_assert(state >= ORDER_STATE_SUBSCRIBED &&
     state <= ORDER_STATE_COMPLETED, "invalid state");
    bon_assert(ord.state != ORDER_STATE_COMPLETED, "order completed");

    auto now_t = now();
    order up_ord = {id, ord.buyer, ord.crate_id, ord.crate_num, now_t, now_t, state};

    this->ords_update(up_ord);
}

void subscription::unsubscribe(uint64_t id)
{
    require_auth(_self);

    auto it = order_table.find(id);
    const auto &ord = *it;
    bon_assert(it != order_table.end(), "invalid id;");
    this->ords_remove(id);
}
