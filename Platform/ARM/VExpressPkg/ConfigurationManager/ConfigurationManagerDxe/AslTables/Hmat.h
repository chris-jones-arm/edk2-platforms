/**
 * Various definitions for needed for Hmat.c when copying across from SgiPkg.
 */

#ifndef __HMAT_H__
#define __HMAT_H__

//
// ACPI table information used to initialize tables.
//
#define EFI_ACPI_ARM_OEM_ID           'A','R','M','L','T','D'   // OEMID 6 bytes long
#define EFI_ACPI_ARM_OEM_TABLE_ID     SIGNATURE_64 ('A','R','M','S','G','I',' ',' ') // OEM table id 8 bytes long
#define EFI_ACPI_ARM_OEM_REVISION     0x20140727
#define EFI_ACPI_ARM_CREATOR_ID       SIGNATURE_32('A','R','M',' ')
#define EFI_ACPI_ARM_CREATOR_REVISION 0x00000099

#define CHIP_CNT                      4
#define INITATOR_PROXIMITY_DOMAIN_CNT 4
#define TARGET_PROXIMITY_DOMAIN_CNT   4

typedef struct InitiatorTargetProximityMatrix {
  UINT32  InitatorProximityDomain[INITATOR_PROXIMITY_DOMAIN_CNT];
  UINT32  TargetProximityDomain[TARGET_PROXIMITY_DOMAIN_CNT];
  UINT16  MatrixEntry[INITATOR_PROXIMITY_DOMAIN_CNT * TARGET_PROXIMITY_DOMAIN_CNT];
} INITIATOR_TARGET_PROXIMITY_MATRIX;

typedef struct {
  EFI_ACPI_6_3_HETEROGENEOUS_MEMORY_ATTRIBUTE_TABLE_HEADER                Header;
  EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_PROXIMITY_DOMAIN_ATTRIBUTES          Proximity[CHIP_CNT];
  EFI_ACPI_6_3_HMAT_STRUCTURE_SYSTEM_LOCALITY_LATENCY_AND_BANDWIDTH_INFO  LatencyInfo;
  INITIATOR_TARGET_PROXIMITY_MATRIX                                       Matrix;
  EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO                      MemSideCache0;
  EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO                      MemSideCache1;
  EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO                      MemSideCache2;
  EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO                      MemSideCache3;
} EFI_ACPI_HETEROGENEOUS_MEMORY_ATTRIBUTE_TABLE;

EFI_ACPI_DESCRIPTION_HEADER HmatHeader;
EFI_ACPI_HETEROGENEOUS_MEMORY_ATTRIBUTE_TABLE HmatTable;

// Memory Proximity Domain Attributes Structure
// Refer Section 5.2.27.3 in ACPI Specification, Version 6.3
#define EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_PROXIMITY_DOMAIN_ATTRIBUTES_INIT(   \
    Flags, ProximityDomainForAttachedIntiator, ProximityDomainForMemory)       \
  {                                                                            \
    EFI_ACPI_6_3_HMAT_TYPE_MEMORY_PROXIMITY_DOMAIN_ATTRIBUTES,                 \
    {                                                                          \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE                                                   \
    },                                                                         \
    sizeof (EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_PROXIMITY_DOMAIN_ATTRIBUTES),   \
    {                                                                          \
      Flags,                                                                   \
      0                                                                        \
    },                                                                         \
    {                                                                          \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE                                                   \
    },                                                                         \
    ProximityDomainForAttachedIntiator,                                        \
    ProximityDomainForMemory,                                                  \
    {                                                                          \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE                                                   \
    }                                                                          \
  }

// System Locality Latency and Bandwidth Information Structure
// Refer Section 5.2.27.4 in ACPI Specification, Version 6.3
#define EFI_ACPI_6_3_HMAT_STRUCTURE_SYSTEM_LOCALITY_LATENCY_AND_BANDWIDTH_INFO_INIT(  \
    Flags, DataType, NumInitiatorProximityDomains,                                    \
    NumTargetProximityDomains, EntryBaseUnit)                                         \
  {                                                                                   \
    EFI_ACPI_6_3_HMAT_TYPE_SYSTEM_LOCALITY_LATENCY_AND_BANDWIDTH_INFO,                \
    {                                                                                 \
      EFI_ACPI_RESERVED_BYTE,                                                         \
      EFI_ACPI_RESERVED_BYTE                                                          \
    },                                                                                \
    sizeof (EFI_ACPI_6_3_HMAT_STRUCTURE_SYSTEM_LOCALITY_LATENCY_AND_BANDWIDTH_INFO) + \
      (4 * NumInitiatorProximityDomains) + (4 * NumTargetProximityDomains) +          \
      (2 * NumInitiatorProximityDomains * NumTargetProximityDomains),                 \
    {                                                                                 \
      Flags,                                                                          \
      0                                                                               \
    },                                                                                \
    DataType,                                                                         \
    {                                                                                 \
      EFI_ACPI_RESERVED_BYTE,                                                         \
      EFI_ACPI_RESERVED_BYTE                                                          \
    },                                                                                \
    NumInitiatorProximityDomains,                                                     \
    NumTargetProximityDomains,                                                        \
    {                                                                                 \
      EFI_ACPI_RESERVED_BYTE,                                                         \
      EFI_ACPI_RESERVED_BYTE,                                                         \
      EFI_ACPI_RESERVED_BYTE,                                                         \
      EFI_ACPI_RESERVED_BYTE                                                          \
    },                                                                                \
    EntryBaseUnit                                                                     \
  }

// Memory Side Cache Information Structure
// Refer Section 5.2.27.5 in ACPI Specification, Version 6.3
#define EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO_INIT(               \
    MemoryProximityDomain, MemorySideCacheSize, CacheAttributes,               \
    NumberOfSmbiosHandles)                                                     \
  {                                                                            \
    EFI_ACPI_6_3_HMAT_TYPE_MEMORY_SIDE_CACHE_INFO,                             \
    {                                                                          \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE                                                   \
    },                                                                         \
    sizeof (EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO) +              \
      (NumberOfSmbiosHandles * 2),                                             \
    MemoryProximityDomain,                                                     \
    {                                                                          \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE                                                   \
    },                                                                         \
    MemorySideCacheSize,                                                       \
    CacheAttributes,                                                           \
    {                                                                          \
      EFI_ACPI_RESERVED_BYTE,                                                  \
      EFI_ACPI_RESERVED_BYTE                                                   \
    },                                                                         \
    NumberOfSmbiosHandles                                                      \
  }

/** A macro to initialise the Memory Side Cache Information Attributes.
    See Table 5.124 in ACPI Specification, Version 6.3

  @param [in] TotalCacheLevels    Total Cache Levels for this Memory Proximity.
  @param [in] CacheLevel          Cache Level described in this structure.
  @param [in] CacheAssociativity  Cache Associativity.
  @param [in] WritePolicy         Write Policy.
  @param [in] CacheLineSize       Cache Line size in bytes.
**/
#define HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO_CACHE_ATTRIBUTES_INIT(           \
  TotalCacheLevels, CacheLevel, CacheAssociativity, WritePolicy, CacheLineSize \
  )                                                                            \
{                                                                              \
  TotalCacheLevels, CacheLevel, CacheAssociativity, WritePolicy, CacheLineSize \
}

// A macro to initialise the common header part of EFI ACPI tables as defined by
// EFI_ACPI_DESCRIPTION_HEADER structure.
#define ARM_ACPI_HEADER(Signature, Type, Revision) {             \
    Signature,                      /* UINT32  Signature */       \
    sizeof (Type),                  /* UINT32  Length */          \
    Revision,                       /* UINT8   Revision */        \
    0,                              /* UINT8   Checksum */        \
    { EFI_ACPI_ARM_OEM_ID },        /* UINT8   OemId[6] */        \
    EFI_ACPI_ARM_OEM_TABLE_ID,      /* UINT64  OemTableId */      \
    EFI_ACPI_ARM_OEM_REVISION,      /* UINT32  OemRevision */     \
    EFI_ACPI_ARM_CREATOR_ID,        /* UINT32  CreatorId */       \
    EFI_ACPI_ARM_CREATOR_REVISION   /* UINT32  CreatorRevision */ \
  }

#endif /* __HMAT_H__ */
