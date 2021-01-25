// clang-format off

// C0CR
//
// DMAMux - DMA request line multiplexer channel x control register
//
//   Offset: 0x000
ETL_BFF_REG_RW(uint32_t, C0CR,
  // 31:29 reserved
  // Synchronization input selected
  ETL_BFF_FIELD(28:24, uint8_t, SYNC_ID)
  // Number of DMA requests to forward Defines the number of DMA requests
  // forwarded before output event is generated. In synchronous mode, it also
  // defines the number of DMA requests to forward after a synchronization
  // event, then stop forwarding. The actual number of DMA requests forwarded is
  // NBREQ+1. Note: This field can only be written when both SE and EGE bits are
  // reset.
  ETL_BFF_FIELD(23:19, uint8_t, NBREQ)
  // Synchronization event type selector Defines the synchronization event on the
  // selected synchronization input:
  ETL_BFF_FIELD(18:17, uint8_t, SPOL)
  // Synchronous operating mode enable/disable
  ETL_BFF_FIELD(16:16, bool, SE)
  // 15:10 reserved
  // Event generation enable/disable
  ETL_BFF_FIELD(9:9, bool, EGE)
  // Interrupt enable at synchronization event overrun
  ETL_BFF_FIELD(8:8, bool, SOIE)
  // 7 reserved
  // Input DMA request line selected
  ETL_BFF_FIELD(6:0, uint8_t, DMAREQ_ID)
)

// C1CR
//
// DMAMux - DMA request line multiplexer channel x control register
//
//   Offset: 0x004
ETL_BFF_REG_RW(uint32_t, C1CR,
  // 31:29 reserved
  // Synchronization input selected
  ETL_BFF_FIELD(28:24, uint8_t, SYNC_ID)
  // Number of DMA requests to forward Defines the number of DMA requests
  // forwarded before output event is generated. In synchronous mode, it also
  // defines the number of DMA requests to forward after a synchronization
  // event, then stop forwarding. The actual number of DMA requests forwarded is
  // NBREQ+1. Note: This field can only be written when both SE and EGE bits are
  // reset.
  ETL_BFF_FIELD(23:19, uint8_t, NBREQ)
  // Synchronization event type selector Defines the synchronization event on the
  // selected synchronization input:
  ETL_BFF_FIELD(18:17, uint8_t, SPOL)
  // Synchronous operating mode enable/disable
  ETL_BFF_FIELD(16:16, bool, SE)
  // 15:10 reserved
  // Event generation enable/disable
  ETL_BFF_FIELD(9:9, bool, EGE)
  // Interrupt enable at synchronization event overrun
  ETL_BFF_FIELD(8:8, bool, SOIE)
  // 7 reserved
  // Input DMA request line selected
  ETL_BFF_FIELD(6:0, uint8_t, DMAREQ_ID)
)

// C2CR
//
// DMAMux - DMA request line multiplexer channel x control register
//
//   Offset: 0x008
ETL_BFF_REG_RW(uint32_t, C2CR,
  // 31:29 reserved
  // Synchronization input selected
  ETL_BFF_FIELD(28:24, uint8_t, SYNC_ID)
  // Number of DMA requests to forward Defines the number of DMA requests
  // forwarded before output event is generated. In synchronous mode, it also
  // defines the number of DMA requests to forward after a synchronization
  // event, then stop forwarding. The actual number of DMA requests forwarded is
  // NBREQ+1. Note: This field can only be written when both SE and EGE bits are
  // reset.
  ETL_BFF_FIELD(23:19, uint8_t, NBREQ)
  // Synchronization event type selector Defines the synchronization event on the
  // selected synchronization input:
  ETL_BFF_FIELD(18:17, uint8_t, SPOL)
  // Synchronous operating mode enable/disable
  ETL_BFF_FIELD(16:16, bool, SE)
  // 15:10 reserved
  // Event generation enable/disable
  ETL_BFF_FIELD(9:9, bool, EGE)
  // Interrupt enable at synchronization event overrun
  ETL_BFF_FIELD(8:8, bool, SOIE)
  // 7 reserved
  // Input DMA request line selected
  ETL_BFF_FIELD(6:0, uint8_t, DMAREQ_ID)
)

// C3CR
//
// DMAMux - DMA request line multiplexer channel x control register
//
//   Offset: 0x00C
ETL_BFF_REG_RW(uint32_t, C3CR,
  // 31:29 reserved
  // Synchronization input selected
  ETL_BFF_FIELD(28:24, uint8_t, SYNC_ID)
  // Number of DMA requests to forward Defines the number of DMA requests
  // forwarded before output event is generated. In synchronous mode, it also
  // defines the number of DMA requests to forward after a synchronization
  // event, then stop forwarding. The actual number of DMA requests forwarded is
  // NBREQ+1. Note: This field can only be written when both SE and EGE bits are
  // reset.
  ETL_BFF_FIELD(23:19, uint8_t, NBREQ)
  // Synchronization event type selector Defines the synchronization event on the
  // selected synchronization input:
  ETL_BFF_FIELD(18:17, uint8_t, SPOL)
  // Synchronous operating mode enable/disable
  ETL_BFF_FIELD(16:16, bool, SE)
  // 15:10 reserved
  // Event generation enable/disable
  ETL_BFF_FIELD(9:9, bool, EGE)
  // Interrupt enable at synchronization event overrun
  ETL_BFF_FIELD(8:8, bool, SOIE)
  // 7 reserved
  // Input DMA request line selected
  ETL_BFF_FIELD(6:0, uint8_t, DMAREQ_ID)
)

// C4CR
//
// DMAMux - DMA request line multiplexer channel x control register
//
//   Offset: 0x010
ETL_BFF_REG_RW(uint32_t, C4CR,
  // 31:29 reserved
  // Synchronization input selected
  ETL_BFF_FIELD(28:24, uint8_t, SYNC_ID)
  // Number of DMA requests to forward Defines the number of DMA requests
  // forwarded before output event is generated. In synchronous mode, it also
  // defines the number of DMA requests to forward after a synchronization
  // event, then stop forwarding. The actual number of DMA requests forwarded is
  // NBREQ+1. Note: This field can only be written when both SE and EGE bits are
  // reset.
  ETL_BFF_FIELD(23:19, uint8_t, NBREQ)
  // Synchronization event type selector Defines the synchronization event on the
  // selected synchronization input:
  ETL_BFF_FIELD(18:17, uint8_t, SPOL)
  // Synchronous operating mode enable/disable
  ETL_BFF_FIELD(16:16, bool, SE)
  // 15:10 reserved
  // Event generation enable/disable
  ETL_BFF_FIELD(9:9, bool, EGE)
  // Interrupt enable at synchronization event overrun
  ETL_BFF_FIELD(8:8, bool, SOIE)
  // 7 reserved
  // Input DMA request line selected
  ETL_BFF_FIELD(6:0, uint8_t, DMAREQ_ID)
)

// C5CR
//
// DMAMux - DMA request line multiplexer channel x control register
//
//   Offset: 0x014
ETL_BFF_REG_RW(uint32_t, C5CR,
  // 31:29 reserved
  // Synchronization input selected
  ETL_BFF_FIELD(28:24, uint8_t, SYNC_ID)
  // Number of DMA requests to forward Defines the number of DMA requests
  // forwarded before output event is generated. In synchronous mode, it also
  // defines the number of DMA requests to forward after a synchronization
  // event, then stop forwarding. The actual number of DMA requests forwarded is
  // NBREQ+1. Note: This field can only be written when both SE and EGE bits are
  // reset.
  ETL_BFF_FIELD(23:19, uint8_t, NBREQ)
  // Synchronization event type selector Defines the synchronization event on the
  // selected synchronization input:
  ETL_BFF_FIELD(18:17, uint8_t, SPOL)
  // Synchronous operating mode enable/disable
  ETL_BFF_FIELD(16:16, bool, SE)
  // 15:10 reserved
  // Event generation enable/disable
  ETL_BFF_FIELD(9:9, bool, EGE)
  // Interrupt enable at synchronization event overrun
  ETL_BFF_FIELD(8:8, bool, SOIE)
  // 7 reserved
  // Input DMA request line selected
  ETL_BFF_FIELD(6:0, uint8_t, DMAREQ_ID)
)

// C6CR
//
// DMAMux - DMA request line multiplexer channel x control register
//
//   Offset: 0x018
ETL_BFF_REG_RW(uint32_t, C6CR,
  // 31:29 reserved
  // Synchronization input selected
  ETL_BFF_FIELD(28:24, uint8_t, SYNC_ID)
  // Number of DMA requests to forward Defines the number of DMA requests
  // forwarded before output event is generated. In synchronous mode, it also
  // defines the number of DMA requests to forward after a synchronization
  // event, then stop forwarding. The actual number of DMA requests forwarded is
  // NBREQ+1. Note: This field can only be written when both SE and EGE bits are
  // reset.
  ETL_BFF_FIELD(23:19, uint8_t, NBREQ)
  // Synchronization event type selector Defines the synchronization event on the
  // selected synchronization input:
  ETL_BFF_FIELD(18:17, uint8_t, SPOL)
  // Synchronous operating mode enable/disable
  ETL_BFF_FIELD(16:16, bool, SE)
  // 15:10 reserved
  // Event generation enable/disable
  ETL_BFF_FIELD(9:9, bool, EGE)
  // Interrupt enable at synchronization event overrun
  ETL_BFF_FIELD(8:8, bool, SOIE)
  // 7 reserved
  // Input DMA request line selected
  ETL_BFF_FIELD(6:0, uint8_t, DMAREQ_ID)
)

// C7CR
//
// DMAMux - DMA request line multiplexer channel x control register
//
//   Offset: 0x01C
ETL_BFF_REG_RW(uint32_t, C7CR,
  // 31:29 reserved
  // Synchronization input selected
  ETL_BFF_FIELD(28:24, uint8_t, SYNC_ID)
  // Number of DMA requests to forward Defines the number of DMA requests
  // forwarded before output event is generated. In synchronous mode, it also
  // defines the number of DMA requests to forward after a synchronization
  // event, then stop forwarding. The actual number of DMA requests forwarded is
  // NBREQ+1. Note: This field can only be written when both SE and EGE bits are
  // reset.
  ETL_BFF_FIELD(23:19, uint8_t, NBREQ)
  // Synchronization event type selector Defines the synchronization event on the
  // selected synchronization input:
  ETL_BFF_FIELD(18:17, uint8_t, SPOL)
  // Synchronous operating mode enable/disable
  ETL_BFF_FIELD(16:16, bool, SE)
  // 15:10 reserved
  // Event generation enable/disable
  ETL_BFF_FIELD(9:9, bool, EGE)
  // Interrupt enable at synchronization event overrun
  ETL_BFF_FIELD(8:8, bool, SOIE)
  // 7 reserved
  // Input DMA request line selected
  ETL_BFF_FIELD(6:0, uint8_t, DMAREQ_ID)
)

// C8CR
//
// DMAMux - DMA request line multiplexer channel x control register
//
//   Offset: 0x020
ETL_BFF_REG_RW(uint32_t, C8CR,
  // 31:29 reserved
  // Synchronization input selected
  ETL_BFF_FIELD(28:24, uint8_t, SYNC_ID)
  // Number of DMA requests to forward Defines the number of DMA requests
  // forwarded before output event is generated. In synchronous mode, it also
  // defines the number of DMA requests to forward after a synchronization
  // event, then stop forwarding. The actual number of DMA requests forwarded is
  // NBREQ+1. Note: This field can only be written when both SE and EGE bits are
  // reset.
  ETL_BFF_FIELD(23:19, uint8_t, NBREQ)
  // Synchronization event type selector Defines the synchronization event on the
  // selected synchronization input:
  ETL_BFF_FIELD(18:17, uint8_t, SPOL)
  // Synchronous operating mode enable/disable
  ETL_BFF_FIELD(16:16, bool, SE)
  // 15:10 reserved
  // Event generation enable/disable
  ETL_BFF_FIELD(9:9, bool, EGE)
  // Interrupt enable at synchronization event overrun
  ETL_BFF_FIELD(8:8, bool, SOIE)
  // 7 reserved
  // Input DMA request line selected
  ETL_BFF_FIELD(6:0, uint8_t, DMAREQ_ID)
)

// C9CR
//
// DMAMux - DMA request line multiplexer channel x control register
//
//   Offset: 0x024
ETL_BFF_REG_RW(uint32_t, C9CR,
  // 31:29 reserved
  // Synchronization input selected
  ETL_BFF_FIELD(28:24, uint8_t, SYNC_ID)
  // Number of DMA requests to forward Defines the number of DMA requests
  // forwarded before output event is generated. In synchronous mode, it also
  // defines the number of DMA requests to forward after a synchronization
  // event, then stop forwarding. The actual number of DMA requests forwarded is
  // NBREQ+1. Note: This field can only be written when both SE and EGE bits are
  // reset.
  ETL_BFF_FIELD(23:19, uint8_t, NBREQ)
  // Synchronization event type selector Defines the synchronization event on the
  // selected synchronization input:
  ETL_BFF_FIELD(18:17, uint8_t, SPOL)
  // Synchronous operating mode enable/disable
  ETL_BFF_FIELD(16:16, bool, SE)
  // 15:10 reserved
  // Event generation enable/disable
  ETL_BFF_FIELD(9:9, bool, EGE)
  // Interrupt enable at synchronization event overrun
  ETL_BFF_FIELD(8:8, bool, SOIE)
  // 7 reserved
  // Input DMA request line selected
  ETL_BFF_FIELD(6:0, uint8_t, DMAREQ_ID)
)

// C10CR
//
// DMAMux - DMA request line multiplexer channel x control register
//
//   Offset: 0x028
ETL_BFF_REG_RW(uint32_t, C10CR,
  // 31:29 reserved
  // Synchronization input selected
  ETL_BFF_FIELD(28:24, uint8_t, SYNC_ID)
  // Number of DMA requests to forward Defines the number of DMA requests
  // forwarded before output event is generated. In synchronous mode, it also
  // defines the number of DMA requests to forward after a synchronization
  // event, then stop forwarding. The actual number of DMA requests forwarded is
  // NBREQ+1. Note: This field can only be written when both SE and EGE bits are
  // reset.
  ETL_BFF_FIELD(23:19, uint8_t, NBREQ)
  // Synchronization event type selector Defines the synchronization event on the
  // selected synchronization input:
  ETL_BFF_FIELD(18:17, uint8_t, SPOL)
  // Synchronous operating mode enable/disable
  ETL_BFF_FIELD(16:16, bool, SE)
  // 15:10 reserved
  // Event generation enable/disable
  ETL_BFF_FIELD(9:9, bool, EGE)
  // Interrupt enable at synchronization event overrun
  ETL_BFF_FIELD(8:8, bool, SOIE)
  // 7 reserved
  // Input DMA request line selected
  ETL_BFF_FIELD(6:0, uint8_t, DMAREQ_ID)
)

// C11CR
//
// DMAMux - DMA request line multiplexer channel x control register
//
//   Offset: 0x02C
ETL_BFF_REG_RW(uint32_t, C11CR,
  // 31:29 reserved
  // Synchronization input selected
  ETL_BFF_FIELD(28:24, uint8_t, SYNC_ID)
  // Number of DMA requests to forward Defines the number of DMA requests
  // forwarded before output event is generated. In synchronous mode, it also
  // defines the number of DMA requests to forward after a synchronization
  // event, then stop forwarding. The actual number of DMA requests forwarded is
  // NBREQ+1. Note: This field can only be written when both SE and EGE bits are
  // reset.
  ETL_BFF_FIELD(23:19, uint8_t, NBREQ)
  // Synchronization event type selector Defines the synchronization event on the
  // selected synchronization input:
  ETL_BFF_FIELD(18:17, uint8_t, SPOL)
  // Synchronous operating mode enable/disable
  ETL_BFF_FIELD(16:16, bool, SE)
  // 15:10 reserved
  // Event generation enable/disable
  ETL_BFF_FIELD(9:9, bool, EGE)
  // Interrupt enable at synchronization event overrun
  ETL_BFF_FIELD(8:8, bool, SOIE)
  // 7 reserved
  // Input DMA request line selected
  ETL_BFF_FIELD(6:0, uint8_t, DMAREQ_ID)
)

// C12CR
//
// DMAMux - DMA request line multiplexer channel x control register
//
//   Offset: 0x030
ETL_BFF_REG_RW(uint32_t, C12CR,
  // 31:29 reserved
  // Synchronization input selected
  ETL_BFF_FIELD(28:24, uint8_t, SYNC_ID)
  // Number of DMA requests to forward Defines the number of DMA requests
  // forwarded before output event is generated. In synchronous mode, it also
  // defines the number of DMA requests to forward after a synchronization
  // event, then stop forwarding. The actual number of DMA requests forwarded is
  // NBREQ+1. Note: This field can only be written when both SE and EGE bits are
  // reset.
  ETL_BFF_FIELD(23:19, uint8_t, NBREQ)
  // Synchronization event type selector Defines the synchronization event on the
  // selected synchronization input:
  ETL_BFF_FIELD(18:17, uint8_t, SPOL)
  // Synchronous operating mode enable/disable
  ETL_BFF_FIELD(16:16, bool, SE)
  // 15:10 reserved
  // Event generation enable/disable
  ETL_BFF_FIELD(9:9, bool, EGE)
  // Interrupt enable at synchronization event overrun
  ETL_BFF_FIELD(8:8, bool, SOIE)
  // 7 reserved
  // Input DMA request line selected
  ETL_BFF_FIELD(6:0, uint8_t, DMAREQ_ID)
)

// C13CR
//
// DMAMux - DMA request line multiplexer channel x control register
//
//   Offset: 0x034
ETL_BFF_REG_RW(uint32_t, C13CR,
  // 31:29 reserved
  // Synchronization input selected
  ETL_BFF_FIELD(28:24, uint8_t, SYNC_ID)
  // Number of DMA requests to forward Defines the number of DMA requests
  // forwarded before output event is generated. In synchronous mode, it also
  // defines the number of DMA requests to forward after a synchronization
  // event, then stop forwarding. The actual number of DMA requests forwarded is
  // NBREQ+1. Note: This field can only be written when both SE and EGE bits are
  // reset.
  ETL_BFF_FIELD(23:19, uint8_t, NBREQ)
  // Synchronization event type selector Defines the synchronization event on the
  // selected synchronization input:
  ETL_BFF_FIELD(18:17, uint8_t, SPOL)
  // Synchronous operating mode enable/disable
  ETL_BFF_FIELD(16:16, bool, SE)
  // 15:10 reserved
  // Event generation enable/disable
  ETL_BFF_FIELD(9:9, bool, EGE)
  // Interrupt enable at synchronization event overrun
  ETL_BFF_FIELD(8:8, bool, SOIE)
  // 7 reserved
  // Input DMA request line selected
  ETL_BFF_FIELD(6:0, uint8_t, DMAREQ_ID)
)

// C14CR
//
// DMAMux - DMA request line multiplexer channel x control register
//
//   Offset: 0x038
ETL_BFF_REG_RW(uint32_t, C14CR,
  // 31:29 reserved
  // Synchronization input selected
  ETL_BFF_FIELD(28:24, uint8_t, SYNC_ID)
  // Number of DMA requests to forward Defines the number of DMA requests
  // forwarded before output event is generated. In synchronous mode, it also
  // defines the number of DMA requests to forward after a synchronization
  // event, then stop forwarding. The actual number of DMA requests forwarded is
  // NBREQ+1. Note: This field can only be written when both SE and EGE bits are
  // reset.
  ETL_BFF_FIELD(23:19, uint8_t, NBREQ)
  // Synchronization event type selector Defines the synchronization event on the
  // selected synchronization input:
  ETL_BFF_FIELD(18:17, uint8_t, SPOL)
  // Synchronous operating mode enable/disable
  ETL_BFF_FIELD(16:16, bool, SE)
  // 15:10 reserved
  // Event generation enable/disable
  ETL_BFF_FIELD(9:9, bool, EGE)
  // Interrupt enable at synchronization event overrun
  ETL_BFF_FIELD(8:8, bool, SOIE)
  // 7 reserved
  // Input DMA request line selected
  ETL_BFF_FIELD(6:0, uint8_t, DMAREQ_ID)
)

// C15CR
//
// DMAMux - DMA request line multiplexer channel x control register
//
//   Offset: 0x03C
ETL_BFF_REG_RW(uint32_t, C15CR,
  // 31:29 reserved
  // Synchronization input selected
  ETL_BFF_FIELD(28:24, uint8_t, SYNC_ID)
  // Number of DMA requests to forward Defines the number of DMA requests
  // forwarded before output event is generated. In synchronous mode, it also
  // defines the number of DMA requests to forward after a synchronization
  // event, then stop forwarding. The actual number of DMA requests forwarded is
  // NBREQ+1. Note: This field can only be written when both SE and EGE bits are
  // reset.
  ETL_BFF_FIELD(23:19, uint8_t, NBREQ)
  // Synchronization event type selector Defines the synchronization event on the
  // selected synchronization input:
  ETL_BFF_FIELD(18:17, uint8_t, SPOL)
  // Synchronous operating mode enable/disable
  ETL_BFF_FIELD(16:16, bool, SE)
  // 15:10 reserved
  // Event generation enable/disable
  ETL_BFF_FIELD(9:9, bool, EGE)
  // Interrupt enable at synchronization event overrun
  ETL_BFF_FIELD(8:8, bool, SOIE)
  // 7 reserved
  // Input DMA request line selected
  ETL_BFF_FIELD(6:0, uint8_t, DMAREQ_ID)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved15, 16)

// CSR
//
// DMAMUX request line multiplexer interrupt channel status register
//
//   Offset: 0x080
ETL_BFF_REG_RO(uint32_t, CSR,
  // 31:16 reserved
  // Synchronization overrun event flag
  ETL_BFF_FIELD(15:15, bool, SOF15)
  // Synchronization overrun event flag
  ETL_BFF_FIELD(14:14, bool, SOF14)
  // Synchronization overrun event flag
  ETL_BFF_FIELD(13:13, bool, SOF13)
  // Synchronization overrun event flag
  ETL_BFF_FIELD(12:12, bool, SOF12)
  // Synchronization overrun event flag
  ETL_BFF_FIELD(11:11, bool, SOF11)
  // Synchronization overrun event flag
  ETL_BFF_FIELD(10:10, bool, SOF10)
  // Synchronization overrun event flag
  ETL_BFF_FIELD(9:9, bool, SOF9)
  // Synchronization overrun event flag
  ETL_BFF_FIELD(8:8, bool, SOF8)
  // Synchronization overrun event flag
  ETL_BFF_FIELD(7:7, bool, SOF7)
  // Synchronization overrun event flag
  ETL_BFF_FIELD(6:6, bool, SOF6)
  // Synchronization overrun event flag
  ETL_BFF_FIELD(5:5, bool, SOF5)
  // Synchronization overrun event flag
  ETL_BFF_FIELD(4:4, bool, SOF4)
  // Synchronization overrun event flag
  ETL_BFF_FIELD(3:3, bool, SOF3)
  // Synchronization overrun event flag
  ETL_BFF_FIELD(2:2, bool, SOF2)
  // Synchronization overrun event flag
  ETL_BFF_FIELD(1:1, bool, SOF1)
  // Synchronization overrun event flag
  ETL_BFF_FIELD(0:0, bool, SOF0)
)

// CFR
//
// DMAMUX request line multiplexer interrupt clear flag register
//
//   Offset: 0x084
ETL_BFF_REG_RW(uint32_t, CFR,
  // 31:16 reserved
  // Clear synchronization overrun event flag
  ETL_BFF_FIELD(15:15, bool, CSOF15)
  // Clear synchronization overrun event flag
  ETL_BFF_FIELD(14:14, bool, CSOF14)
  // Clear synchronization overrun event flag
  ETL_BFF_FIELD(13:13, bool, CSOF13)
  // Clear synchronization overrun event flag
  ETL_BFF_FIELD(12:12, bool, CSOF12)
  // Clear synchronization overrun event flag
  ETL_BFF_FIELD(11:11, bool, CSOF11)
  // Clear synchronization overrun event flag
  ETL_BFF_FIELD(10:10, bool, CSOF10)
  // Clear synchronization overrun event flag
  ETL_BFF_FIELD(9:9, bool, CSOF9)
  // Clear synchronization overrun event flag
  ETL_BFF_FIELD(8:8, bool, CSOF8)
  // Clear synchronization overrun event flag
  ETL_BFF_FIELD(7:7, bool, CSOF7)
  // Clear synchronization overrun event flag
  ETL_BFF_FIELD(6:6, bool, CSOF6)
  // Clear synchronization overrun event flag
  ETL_BFF_FIELD(5:5, bool, CSOF5)
  // Clear synchronization overrun event flag
  ETL_BFF_FIELD(4:4, bool, CSOF4)
  // Clear synchronization overrun event flag
  ETL_BFF_FIELD(3:3, bool, CSOF3)
  // Clear synchronization overrun event flag
  ETL_BFF_FIELD(2:2, bool, CSOF2)
  // Clear synchronization overrun event flag
  ETL_BFF_FIELD(1:1, bool, CSOF1)
  // Clear synchronization overrun event flag
  ETL_BFF_FIELD(0:0, bool, CSOF0)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved17, 30)

// RG0CR
//
// DMAMux - DMA request generator channel x control register
//
//   Offset: 0x100
ETL_BFF_REG_RW(uint32_t, RG0CR,
  // 31:24 reserved
  // Number of DMA requests to generate Defines the number of DMA requests
  // generated after a trigger event, then stop generating. The actual number of
  // generated DMA requests is GNBREQ+1. Note: This field can only be written
  // when GE bit is reset.
  ETL_BFF_FIELD(23:19, uint8_t, GNBREQ)
  // DMA request generator trigger event type selection Defines the trigger event
  // on the selected DMA request trigger input
  ETL_BFF_FIELD(18:17, uint8_t, GPOL)
  // DMA request generator channel enable/disable
  ETL_BFF_FIELD(16:16, bool, GE)
  // 15:9 reserved
  // Interrupt enable at trigger event overrun
  ETL_BFF_FIELD(8:8, bool, OIE)
  // 7:5 reserved
  // DMA request trigger input selected
  ETL_BFF_FIELD(4:0, uint8_t, SIG_ID)
)

// RG1CR
//
// DMAMux - DMA request generator channel x control register
//
//   Offset: 0x104
ETL_BFF_REG_RW(uint32_t, RG1CR,
  // 31:24 reserved
  // Number of DMA requests to generate Defines the number of DMA requests
  // generated after a trigger event, then stop generating. The actual number of
  // generated DMA requests is GNBREQ+1. Note: This field can only be written
  // when GE bit is reset.
  ETL_BFF_FIELD(23:19, uint8_t, GNBREQ)
  // DMA request generator trigger event type selection Defines the trigger event
  // on the selected DMA request trigger input
  ETL_BFF_FIELD(18:17, uint8_t, GPOL)
  // DMA request generator channel enable/disable
  ETL_BFF_FIELD(16:16, bool, GE)
  // 15:9 reserved
  // Interrupt enable at trigger event overrun
  ETL_BFF_FIELD(8:8, bool, OIE)
  // 7:5 reserved
  // DMA request trigger input selected
  ETL_BFF_FIELD(4:0, uint8_t, SIG_ID)
)

// RG2CR
//
// DMAMux - DMA request generator channel x control register
//
//   Offset: 0x108
ETL_BFF_REG_RW(uint32_t, RG2CR,
  // 31:24 reserved
  // Number of DMA requests to generate Defines the number of DMA requests
  // generated after a trigger event, then stop generating. The actual number of
  // generated DMA requests is GNBREQ+1. Note: This field can only be written
  // when GE bit is reset.
  ETL_BFF_FIELD(23:19, uint8_t, GNBREQ)
  // DMA request generator trigger event type selection Defines the trigger event
  // on the selected DMA request trigger input
  ETL_BFF_FIELD(18:17, uint8_t, GPOL)
  // DMA request generator channel enable/disable
  ETL_BFF_FIELD(16:16, bool, GE)
  // 15:9 reserved
  // Interrupt enable at trigger event overrun
  ETL_BFF_FIELD(8:8, bool, OIE)
  // 7:5 reserved
  // DMA request trigger input selected
  ETL_BFF_FIELD(4:0, uint8_t, SIG_ID)
)

// RG3CR
//
// DMAMux - DMA request generator channel x control register
//
//   Offset: 0x10C
ETL_BFF_REG_RW(uint32_t, RG3CR,
  // 31:24 reserved
  // Number of DMA requests to generate Defines the number of DMA requests
  // generated after a trigger event, then stop generating. The actual number of
  // generated DMA requests is GNBREQ+1. Note: This field can only be written
  // when GE bit is reset.
  ETL_BFF_FIELD(23:19, uint8_t, GNBREQ)
  // DMA request generator trigger event type selection Defines the trigger event
  // on the selected DMA request trigger input
  ETL_BFF_FIELD(18:17, uint8_t, GPOL)
  // DMA request generator channel enable/disable
  ETL_BFF_FIELD(16:16, bool, GE)
  // 15:9 reserved
  // Interrupt enable at trigger event overrun
  ETL_BFF_FIELD(8:8, bool, OIE)
  // 7:5 reserved
  // DMA request trigger input selected
  ETL_BFF_FIELD(4:0, uint8_t, SIG_ID)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved21, 12)

// RGSR
//
// DMAMux - DMA request generator status register
//
//   Offset: 0x140
ETL_BFF_REG_RO(uint32_t, RGSR,
  // 31:4 reserved
  // Trigger event overrun flag The flag is set when a trigger event occurs on DMA
  // request generator channel x, while the DMA request generator counter value
  // is lower than GNBREQ. The flag is cleared by writing 1 to the corresponding
  // COFx bit in DMAMUX_RGCFR register.
  ETL_BFF_FIELD(3:3, bool, OF3)
  // Trigger event overrun flag The flag is set when a trigger event occurs on DMA
  // request generator channel x, while the DMA request generator counter value
  // is lower than GNBREQ. The flag is cleared by writing 1 to the corresponding
  // COFx bit in DMAMUX_RGCFR register.
  ETL_BFF_FIELD(2:2, bool, OF2)
  // Trigger event overrun flag The flag is set when a trigger event occurs on DMA
  // request generator channel x, while the DMA request generator counter value
  // is lower than GNBREQ. The flag is cleared by writing 1 to the corresponding
  // COFx bit in DMAMUX_RGCFR register.
  ETL_BFF_FIELD(1:1, bool, OF1)
  // Trigger event overrun flag The flag is set when a trigger event occurs on DMA
  // request generator channel x, while the DMA request generator counter value
  // is lower than GNBREQ. The flag is cleared by writing 1 to the corresponding
  // COFx bit in DMAMUX_RGCFR register.
  ETL_BFF_FIELD(0:0, bool, OF0)
)

// RGCFR
//
// DMAMux - DMA request generator clear flag register
//
//   Offset: 0x144
ETL_BFF_REG_RW(uint32_t, RGCFR,
  // 31:4 reserved
  // Clear trigger event overrun flag Upon setting, this bit clears the
  // corresponding overrun flag OFx in the DMAMUX_RGCSR register.
  ETL_BFF_FIELD(3:3, bool, COF3)
  // Clear trigger event overrun flag Upon setting, this bit clears the
  // corresponding overrun flag OFx in the DMAMUX_RGCSR register.
  ETL_BFF_FIELD(2:2, bool, COF2)
  // Clear trigger event overrun flag Upon setting, this bit clears the
  // corresponding overrun flag OFx in the DMAMUX_RGCSR register.
  ETL_BFF_FIELD(1:1, bool, COF1)
  // Clear trigger event overrun flag Upon setting, this bit clears the
  // corresponding overrun flag OFx in the DMAMUX_RGCSR register.
  ETL_BFF_FIELD(0:0, bool, COF0)
)

// clang-format on
